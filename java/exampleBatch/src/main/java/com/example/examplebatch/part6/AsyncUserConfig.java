package com.example.examplebatch.part6;

import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;

import com.example.examplebatch.part4.LevelUpJobExecutionListener;
import com.example.examplebatch.part4.SaveUserTasklet;
import com.example.examplebatch.part4.User;
import com.example.examplebatch.part4.UserRepository;
import com.example.examplebatch.part5.JobParametersDecide;
import com.example.examplebatch.part5.OrderStatistics;
import org.springframework.batch.core.Job;
import org.springframework.batch.core.Step;
import org.springframework.batch.core.repository.JobRepository;
import org.springframework.batch.core.step.builder.StepBuilder;
import org.springframework.batch.core.configuration.annotation.JobScope;
import org.springframework.batch.core.job.builder.JobBuilder;
import org.springframework.batch.core.launch.support.RunIdIncrementer;
import org.springframework.batch.integration.async.AsyncItemProcessor;
import org.springframework.batch.integration.async.AsyncItemWriter;
import org.springframework.batch.item.ItemProcessor;
import org.springframework.batch.item.ItemReader;
import org.springframework.batch.item.ItemWriter;
import org.springframework.batch.item.database.JdbcPagingItemReader;
import org.springframework.batch.item.database.JpaPagingItemReader;
import org.springframework.batch.item.database.Order;
import org.springframework.batch.item.database.builder.JdbcPagingItemReaderBuilder;
import org.springframework.batch.item.database.builder.JpaPagingItemReaderBuilder;
import org.springframework.batch.item.file.FlatFileItemWriter;
import org.springframework.batch.item.file.builder.FlatFileItemWriterBuilder;
import org.springframework.batch.item.file.transform.BeanWrapperFieldExtractor;
import org.springframework.batch.item.file.transform.DelimitedLineAggregator;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.core.io.FileSystemResource;
import org.springframework.core.task.TaskExecutor;
import org.springframework.transaction.PlatformTransactionManager;

import jakarta.persistence.EntityManagerFactory;
import javax.sql.DataSource;
import java.time.LocalDate;
import java.time.YearMonth;
import java.time.format.DateTimeFormatter;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.Future;

@Configuration
@Slf4j
@RequiredArgsConstructor
public class AsyncUserConfig {

	private final DataSource dataSource;
	private final JobRepository jobRepository;
	private final PlatformTransactionManager platformTransactionManager;
	private final UserRepository userRepository;
	private final EntityManagerFactory entityManagerFactory;
	private final int CHUNKSIZE = 1000;
	private final String JOB_NAME = "asyncUserJob";

	private final TaskExecutor taskExecutor;


	@Bean(JOB_NAME)
	public Job userJob() throws Exception {
			return new JobBuilder(JOB_NAME, jobRepository)
							.incrementer(new RunIdIncrementer())
							.start(this.saveUserStep())
							.next(this.userLevelUpStep())
							.listener(new LevelUpJobExecutionListener(userRepository))
							.next(new JobParametersDecide("date"))
							.on(JobParametersDecide.CONTINUE.getName())
							.to(this.orderStatisticsStep(null))
							.build()
							.build();
	}

	@Bean(JOB_NAME + "_orderStatisticsStep")
	@JobScope
	public Step orderStatisticsStep(@Value("#{jobParameters[date]}") String date) throws Exception {
			return new StepBuilder(JOB_NAME + "_orderStatisticsStep", jobRepository)
							.<OrderStatistics, OrderStatistics>chunk(CHUNKSIZE, platformTransactionManager)
							.reader(orderStatisticsItemReader(date))
							.writer(orderStatisticsItemWriter(date))
							.build();
	}

	private ItemWriter<? super OrderStatistics> orderStatisticsItemWriter(String date) throws Exception {

			YearMonth yearMonth = YearMonth.parse(date);
			String filename= yearMonth.getYear() + "년_" + yearMonth.getMonthValue() + "월_일별_주문_금액.csv";

			BeanWrapperFieldExtractor<OrderStatistics> fieldExtractor = new BeanWrapperFieldExtractor<>();
			fieldExtractor.setNames(new String[]{"amount", "date"});

			DelimitedLineAggregator<OrderStatistics> lineAggregator = new DelimitedLineAggregator<>();
			lineAggregator.setDelimiter(",");
			lineAggregator.setFieldExtractor(fieldExtractor);

			FlatFileItemWriter<OrderStatistics> itemWriter = new FlatFileItemWriterBuilder<OrderStatistics>()
							.encoding("UTF-8")
							.resource(new FileSystemResource("output/" + filename))
							.lineAggregator(lineAggregator)
							.headerCallback(writer -> writer.write("total_amount, date"))
							.name(JOB_NAME + "_orderStatisticsItemWriter")
							.build();

			itemWriter.afterPropertiesSet();

			return itemWriter;
	}

	private ItemReader<? extends OrderStatistics> orderStatisticsItemReader(String date) throws Exception {
			YearMonth yearMonth = YearMonth.parse(date);

			Map<String, Object> parameters = new HashMap<>();

			parameters.put("startDate", yearMonth.atDay(1));
			parameters.put("endDate", yearMonth.atEndOfMonth());

			Map<String, Order> sortKey = new HashMap<>();
			sortKey.put("created_date", Order.ASCENDING);

			JdbcPagingItemReader<OrderStatistics> itemReader = new JdbcPagingItemReaderBuilder<OrderStatistics>()
							.dataSource(dataSource)
							.rowMapper((rs, rowNum) -> OrderStatistics.builder()
											.amount(rs.getString(1))
											.date(LocalDate.parse(rs.getString(2), DateTimeFormatter.ISO_DATE))
											.build())
							.pageSize(CHUNKSIZE)
							.name(JOB_NAME + "_orderStatisticsItemReader")
							.selectClause("sum(amount), created_date")
							.fromClause("orders")
							.whereClause("created_date >= :startDate and created_date <= :endDate")
							.groupClause("created_date")
							.parameterValues(parameters)
							.sortKeys(sortKey)
							.build();

			itemReader.afterPropertiesSet();

			return itemReader;
	}

	@Bean(JOB_NAME + "_saveUserStep")
	public Step saveUserStep() {
			return new StepBuilder(JOB_NAME + "_saveUserStep", jobRepository)
							.tasklet(new SaveUserTasklet(userRepository), platformTransactionManager)
							.build();
	}

	@Bean(JOB_NAME + "_userLevelUpStep")
	public Step userLevelUpStep() throws Exception {
			return new StepBuilder(JOB_NAME + "_userLevelUpStep", jobRepository)
							.<User, Future<User>>chunk(CHUNKSIZE, platformTransactionManager)
							.reader(itemReader())
							.processor(itemProcessor())
							.writer(itemWriter())
							.build();
	}

	private AsyncItemWriter<User> itemWriter() {

			ItemWriter<User> itemWriter =  users -> users.forEach(User::levelUp);
			AsyncItemWriter<User> asyncItemWriter = new AsyncItemWriter<>();
			asyncItemWriter.setDelegate(itemWriter);

			return asyncItemWriter;

	}

	private AsyncItemProcessor<User,User> itemProcessor() {
			ItemProcessor<User, User> itemProcessor = user -> {
					if (user.availableLevelUp()){
							return user;
					}
					return null;
			};

			AsyncItemProcessor<User, User> asyncItemProcessor = new AsyncItemProcessor<>();
			asyncItemProcessor.setDelegate(itemProcessor);
			asyncItemProcessor.setTaskExecutor(this.taskExecutor);
			return asyncItemProcessor;
	}

	private ItemReader<? extends User> itemReader() throws Exception {
			JpaPagingItemReader<User> itemReader = new JpaPagingItemReaderBuilder<User>()
							.queryString("select u from User u")
							.entityManagerFactory(entityManagerFactory)
							.pageSize(CHUNKSIZE)
							.name(JOB_NAME + "_userItemReader")
							.build();

			itemReader.afterPropertiesSet();

			return itemReader;
	}

}
