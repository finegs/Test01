package com.example.examplebatch.part3;

import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.batch.core.Job;
import org.springframework.batch.core.Step;
import org.springframework.batch.core.configuration.annotation.JobScope;
import org.springframework.batch.core.job.builder.JobBuilder;
import org.springframework.batch.core.launch.support.RunIdIncrementer;
import org.springframework.batch.core.repository.JobRepository;
import org.springframework.batch.core.step.builder.StepBuilder;
import org.springframework.batch.item.ItemProcessor;
import org.springframework.batch.item.ItemReader;
import org.springframework.batch.item.ItemWriter;
import org.springframework.batch.item.database.BeanPropertyItemSqlParameterSourceProvider;
import org.springframework.batch.item.database.JdbcBatchItemWriter;
import org.springframework.batch.item.database.builder.JdbcBatchItemWriterBuilder;
import org.springframework.batch.item.file.FlatFileItemReader;
import org.springframework.batch.item.file.LineMapper;
import org.springframework.batch.item.file.builder.FlatFileItemReaderBuilder;
import org.springframework.batch.item.file.mapping.DefaultLineMapper;
import org.springframework.batch.item.file.transform.DelimitedLineTokenizer;
import org.springframework.batch.item.support.CompositeItemProcessor;
import org.springframework.batch.item.support.builder.CompositeItemProcessorBuilder;
import org.springframework.batch.item.support.builder.CompositeItemWriterBuilder;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.core.io.ClassPathResource;
import org.springframework.transaction.PlatformTransactionManager;
import org.springframework.util.StringUtils;

import javax.sql.DataSource;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

@Slf4j
@RequiredArgsConstructor
@Configuration
public class HomeworkConfig {

    private final DataSource dataSource;
		private final JobRepository jobRepository;
		private  PlatformTransactionManager platformTransactionManager;

    private final static Map<String, Person> persons = new ConcurrentHashMap<>();

    @Bean
    public Job homeworkJob() throws Exception {
        return new JobBuilder("homeworkJob", jobRepository)
                .incrementer(new RunIdIncrementer())
                .start(this.homeworkStep(null))
                .listener(new SavePersonListener.SavePersonJobExecutionListener())
                .listener(new SavePersonListener.SavePersonAnnotationJobExecutionListener())
                .build();
    }

    @Bean
    @JobScope
    public Step homeworkStep(@Value("#{jobParameters[allow_duplicate]}") String allowDuplicate) throws Exception{

        return new StepBuilder("homeworkStep", jobRepository)
                .<Person, Person>chunk(10, platformTransactionManager)
                .reader(csvFileReader())
                .processor(itemProcessor(Boolean.parseBoolean(allowDuplicate)))
                .writer(csvFileWriter())
                .listener(new SavePersonListener.SavePersonStepExecutionListener())
                .faultTolerant()
                .skip(NotFoundNameException.class)
                .skipLimit(2)
                .build();

    }

    private ItemProcessor<? super Person, ? extends Person> itemProcessor(Boolean allowDuplicate) throws Exception {

        ItemProcessor<Person, Person> duplicationProcessor = allowDuplicate ? item -> item : item -> {
            if (persons.containsKey(item.getName())) {
                return null;
            }
            persons.put(item.getName(), item);
            return item;
        };


        ItemProcessor<Person, Person> validationProcessor = item -> {
            if (!StringUtils.hasText(item.getName())) {
                throw new NotFoundNameException();
            }
            return item;
        };

        CompositeItemProcessor<Person,Person> itemProcessor = new CompositeItemProcessorBuilder<Person, Person>()
                .delegates(new PersonValidationRetryProcessor(),validationProcessor, duplicationProcessor)
                .build();

        itemProcessor.afterPropertiesSet();

        return itemProcessor;

    }

    private ItemWriter<? super Person> csvFileWriter() {
        CompositeItemWriterBuilder<Person> writer = new CompositeItemWriterBuilder<>();
        writer.delegates(jdbcBatchItemWriter(), logItemWriter());
        return writer.build();
    }

    private ItemWriter<? super Person> logItemWriter() {
        return items -> items.getItems().stream().map(Person::getName).forEach(id -> log.info("PERSON.NAME : {}", id));
    }

    private ItemWriter<? super Person> jdbcBatchItemWriter() {

        JdbcBatchItemWriter<Person> itemWriter = new JdbcBatchItemWriterBuilder<Person>()
                .dataSource(dataSource)
                .itemSqlParameterSourceProvider(new BeanPropertyItemSqlParameterSourceProvider<>())
                .sql("insert into person(name, age, address) values(:name, :age, :address)")
                .build();

        itemWriter.afterPropertiesSet();

        return itemWriter;
    }
    private ItemProcessor<? super Person, ? extends Person> csvFileProcessor(Boolean allowDuplicate) {

        return allowDuplicate ? item -> item : item -> {
            if(persons.containsKey(item.getName())) {
                return null;
            }
            persons.put(item.getName(), item);
            return item;
        };
    }

    private ItemReader<? extends Person> csvFileReader() throws Exception {

        FlatFileItemReaderBuilder<Person> flatFileReader = new FlatFileItemReaderBuilder<>();
        flatFileReader.name("csvFileReader");
        flatFileReader.encoding("UTF-8");
        flatFileReader.resource(new ClassPathResource("test.csv"));
        flatFileReader.linesToSkip(1);
        flatFileReader.lineMapper(lineMapper());
        FlatFileItemReader<Person> itemReader = flatFileReader.build();

        itemReader.afterPropertiesSet();

        return itemReader;

    }

    private LineMapper<Person> lineMapper() {

        DefaultLineMapper<Person> lineMapper = new DefaultLineMapper<>();
        DelimitedLineTokenizer tokenizer = new DelimitedLineTokenizer();
        tokenizer.setNames("name", "age", "address");
        tokenizer.setDelimiter("/");
        lineMapper.setLineTokenizer(tokenizer);
        lineMapper.setFieldSetMapper(fieldSet -> {
            String name = fieldSet.readString("name");
            String age = fieldSet.readString("age");
            String address = fieldSet.readString("address");

            return new Person(name, age, address);
        });


        return lineMapper;
    }
}
