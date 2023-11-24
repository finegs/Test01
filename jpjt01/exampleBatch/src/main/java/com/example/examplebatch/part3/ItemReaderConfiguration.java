package com.example.examplebatch.part3;

import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.batch.core.Job;
import org.springframework.batch.core.Step;
import org.springframework.batch.core.job.builder.JobBuilder;
import org.springframework.batch.core.launch.support.RunIdIncrementer;
import org.springframework.batch.core.repository.JobRepository;
import org.springframework.batch.core.step.builder.StepBuilder;
import org.springframework.batch.item.ItemWriter;
import org.springframework.batch.item.database.*;
import org.springframework.batch.item.database.builder.JdbcCursorItemReaderBuilder;
import org.springframework.batch.item.database.builder.JdbcPagingItemReaderBuilder;
import org.springframework.batch.item.database.builder.JpaCursorItemReaderBuilder;
import org.springframework.batch.item.file.FlatFileItemReader;
import org.springframework.batch.item.file.LineMapper;
import org.springframework.batch.item.file.mapping.DefaultLineMapper;
import org.springframework.batch.item.file.transform.DelimitedLineTokenizer;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.core.io.ClassPathResource;
import org.springframework.transaction.PlatformTransactionManager;

import jakarta.persistence.EntityManagerFactory;
import javax.sql.DataSource;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

@Configuration
@Slf4j
@RequiredArgsConstructor
public class ItemReaderConfiguration {


    private final DataSource dataSource;
		private final JobRepository jobRepository;
    private final EntityManagerFactory entityManagerFactory;
		private final PlatformTransactionManager platformTransactionManager;

    private static final int chunkSize = 10;


    @Bean
    public Job itemReaderJob() throws Exception {
        return new JobBuilder("itemReaderJob", jobRepository)
                .incrementer(new RunIdIncrementer())
                .start(this.customItemReaderStep())
                .next(this.csvFileItemReaderStep())
                .next(this.jdbcCursorItemReaderStep())
                .next(this.jdbcPagingItemReaderStep())
                .next(this.jpaCursorItemReaderStep())
                .build();
    }



    private Step jdbcPagingItemReaderStep() throws Exception {
        return new StepBuilder("jdbcPagingItemReaderStep", jobRepository)
                .<Person, Person>chunk(chunkSize, platformTransactionManager)
                .reader(jdbcPagingItemReader())
                .writer(itemWriter())
                .build();
    }

    private JdbcPagingItemReader<Person> jdbcPagingItemReader() throws Exception {

        JdbcPagingItemReader<Person> reader = new JdbcPagingItemReaderBuilder<Person>()
                .fetchSize(5)
                .pageSize(5)
                .dataSource(dataSource)
                .rowMapper(((rs, rowNum) 
											-> 
													new Person(rs.getInt(1), 
														rs.getString(2), 
														rs.getString(3), 
														rs.getString(4))))
                .selectClause("id, name, age, address")
                .fromClause("person")
                .sortKeys(Map.of("id", Order.ASCENDING))
                .name("jdbcPagingItemReader")
                .build();

        reader.afterPropertiesSet();
        return reader;
    }

    private Step jdbcCursorItemReaderStep() {
        return new StepBuilder("jdbcCursorItemReaderStep", jobRepository)
                .<Person, Person>chunk(10, platformTransactionManager)
                .reader(jdbcCursorItemReader())
                .writer(itemWriter())
                .build();
    }

    @Bean
    public Step customItemReaderStep() {
        return new StepBuilder("customItemReaderStep", jobRepository)
                .<Person, Person>chunk(10,  platformTransactionManager)
                .reader(new CustomItemReader<>(getItems()))
                .writer(itemWriter())
                .build();
    }


    @Bean
    public Step csvFileItemReaderStep() throws Exception {
        return new StepBuilder("csvFileItemReaderStep", jobRepository)
                .<Person, Person>chunk(10, platformTransactionManager)
                .reader(csvFileItemReader())
                .writer(itemWriter())
                .build();
    }

    @Bean
    public Step jpaCursorItemReaderStep() throws Exception {
        return new StepBuilder("jpaCursorItemReaderStep", jobRepository)
                .<Person, Person>chunk(10, platformTransactionManager)
                .reader(this.jpaCursorItemReader())
                .writer(itemWriter())
                .build();
    }


    private JpaCursorItemReader<Person> jpaCursorItemReader() throws Exception {
        JpaCursorItemReader<Person> itemReader = new JpaCursorItemReaderBuilder<Person>()
                .name("jpaCursorItemReader")
                .entityManagerFactory(entityManagerFactory)
                .queryString("select p from Person p")
                .build();

        itemReader.afterPropertiesSet();

        return itemReader;
    }



    private JdbcCursorItemReader<Person> jdbcCursorItemReader() {
        return new JdbcCursorItemReaderBuilder<Person>()
                .fetchSize(10)
                .dataSource(dataSource)
                .rowMapper((rs, rowNum) -> new Person(
                        rs.getInt(1),
                        rs.getString(2),
                        rs.getString(3),
                        rs.getString(4)
                ))
                .sql("SELECT id, name, age, address FROM person")
                .name("jdbcCursorItemReader")
                .build();
    }


    private FlatFileItemReader<Person> csvFileItemReader() throws Exception {
        FlatFileItemReader<Person> csvFileItemReader = new FlatFileItemReader<>();
        csvFileItemReader.setEncoding("UTF-8");
        csvFileItemReader.setName("csvFileItemReader");
        csvFileItemReader.setResource(new ClassPathResource("test.csv"));
        csvFileItemReader.setLinesToSkip(1);
        csvFileItemReader.setLineMapper(lineMapper());

        csvFileItemReader.afterPropertiesSet();

        return csvFileItemReader;
    }

    private LineMapper<Person> lineMapper() {
        DefaultLineMapper<Person> lineMapper = new DefaultLineMapper<>();
        DelimitedLineTokenizer tokenizer = new DelimitedLineTokenizer();
        tokenizer.setNames("id", "name", "age", "address");
        tokenizer.setDelimiter("/");
        lineMapper.setLineTokenizer(tokenizer);
        lineMapper.setFieldSetMapper(fieldSet -> {
            int id = fieldSet.readInt("id");
            String name = fieldSet.readString("name");
            String age = fieldSet.readString("age");
            String address = fieldSet.readString("address");

            return new Person(id, name, age, address);
        });


        return lineMapper;
    }

    private ItemWriter<Person> itemWriter() {
        return items -> log.info(items.getItems()
								.stream()
                .map(Person::getName)
                .collect(Collectors.joining(", ")));
    }

    private List<Person> getItems() {
        List<Person> items = new ArrayList<>();

        for (int i = 0; i < 100; i++) {
            items.add(new Person(i + 1, "test name" + i, "test age", "test address"));
        }

        return items;
    }

}
