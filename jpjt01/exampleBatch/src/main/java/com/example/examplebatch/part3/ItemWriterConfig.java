package com.example.examplebatch.part3;

import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.batch.core.Job;
import org.springframework.batch.core.Step;
import org.springframework.batch.core.job.builder.JobBuilder;
import org.springframework.batch.core.launch.support.RunIdIncrementer;
import org.springframework.batch.core.repository.JobRepository;
import org.springframework.batch.core.step.builder.StepBuilder;
import org.springframework.batch.item.ItemReader;
import org.springframework.batch.item.ItemWriter;
import org.springframework.batch.item.database.BeanPropertyItemSqlParameterSourceProvider;
import org.springframework.batch.item.database.JdbcBatchItemWriter;
import org.springframework.batch.item.database.JpaItemWriter;
import org.springframework.batch.item.database.builder.JdbcBatchItemWriterBuilder;
import org.springframework.batch.item.database.builder.JpaItemWriterBuilder;
import org.springframework.batch.item.file.FlatFileItemWriter;
import org.springframework.batch.item.file.builder.FlatFileItemWriterBuilder;
import org.springframework.batch.item.file.transform.BeanWrapperFieldExtractor;
import org.springframework.batch.item.file.transform.DelimitedLineAggregator;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.core.io.FileSystemResource;
import org.springframework.transaction.PlatformTransactionManager;

import jakarta.persistence.EntityManagerFactory;
import javax.sql.DataSource;
import java.util.ArrayList;
import java.util.List;

@Configuration
@Slf4j
@RequiredArgsConstructor
public class ItemWriterConfig {


	
	private final DataSource dataSource; 
	private final JobRepository jobRepository; 
  private final EntityManagerFactory entityManagerFactory;
	private final PlatformTransactionManager platformTransactionManager;


    @Bean
    public Job itemWriterJob() throws Exception {
        return new JobBuilder("itemWriterJob", jobRepository)
                .incrementer(new RunIdIncrementer())
                .start(this.csvItemWriterStep())
//                .next(this.JdbcBatchItemWriterStep())
                .next(this.jpaItemWriterStep())
                .build();
    }

    @Bean
    public Step csvItemWriterStep() throws Exception {
        return new StepBuilder("csvItemWriterStep", jobRepository)
                .<Person, Person>chunk(10, platformTransactionManager)
                .reader(itemReader())
                .writer(csvItemWriter())
                .build();
    }


    @Bean
    public Step JdbcBatchItemWriterStep() throws Exception {
        return new StepBuilder("JdbcBatchItemWriterStep", jobRepository)
                .<Person, Person>chunk(10, platformTransactionManager)
                .reader(itemReader())
                .writer(JdbcBatchItemWriter())
                .build();
    }

    @Bean
    public Step jpaItemWriterStep() throws Exception {
        return new StepBuilder("jpaItemWriterStep", jobRepository)
                .<Person, Person>chunk(10, platformTransactionManager)
                .reader(itemReader())
                .writer(jpaItemWriter())
                .build();
    }

    private ItemWriter<? super Person> jpaItemWriter() throws Exception {
        JpaItemWriter<Person> jpaItemWriter = new JpaItemWriterBuilder<Person>()
                .entityManagerFactory(entityManagerFactory)
                .usePersist(true)
                .build();

        jpaItemWriter.afterPropertiesSet();

        return jpaItemWriter;
    }

    private ItemWriter<? super Person> JdbcBatchItemWriter() {

        JdbcBatchItemWriter<Person> itemWriter = new JdbcBatchItemWriterBuilder<Person>()
                .dataSource(dataSource)
                .itemSqlParameterSourceProvider(new BeanPropertyItemSqlParameterSourceProvider<>())
                .sql("insert into person(name, age, address) values(:name, :age, :address)")
                .build();

        itemWriter.afterPropertiesSet();

        return itemWriter;
    }

    private ItemWriter<? super Person> csvItemWriter() throws Exception {

        BeanWrapperFieldExtractor<Person> fieldExtractor = new BeanWrapperFieldExtractor<>();
        fieldExtractor.setNames(new String[]{"id", "name", "age", "address"});

        DelimitedLineAggregator<Person> lineAggregator = new DelimitedLineAggregator<>();
        lineAggregator.setDelimiter(",");
        lineAggregator.setFieldExtractor(fieldExtractor);


        FlatFileItemWriter<Person> csvFileItemWriter = new FlatFileItemWriterBuilder<Person>()
                .name("csvFileItemWriter")
                .lineAggregator(lineAggregator)
                .encoding("UTF-8")
                .headerCallback(writer -> writer.write("id,이름,나이,거주지"))
                .footerCallback(writer -> writer.write("-------------------------------------------\n"))
                .resource(new FileSystemResource("output/test-out.csv"))
                .append(true)
                .build();

        csvFileItemWriter.afterPropertiesSet();

        return csvFileItemWriter;
    }
    private ItemReader<Person> itemReader() {
        return new CustomItemReader<>(getItems());
    }
    private List<Person> getItems() {
        List<Person> items = new ArrayList<>();
        for (int i = 0; i < 100; i++) {
            items.add(new Person( "test name" + i, "test age", "test address"));
        }
        return items;

    }


}
