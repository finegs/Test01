package com.example.examplebatch.part3;

import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.batch.core.Job;
import org.springframework.batch.core.Step;
import org.springframework.batch.core.job.builder.JobBuilder;
import org.springframework.batch.core.launch.support.RunIdIncrementer;
import org.springframework.batch.core.repository.JobRepository;
import org.springframework.batch.core.step.builder.StepBuilder;
import org.springframework.batch.item.ItemProcessor;
import org.springframework.batch.item.ItemReader;
import org.springframework.batch.item.ItemWriter;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.transaction.PlatformTransactionManager;

import java.util.ArrayList;
import java.util.List;

@Configuration
@Slf4j
@RequiredArgsConstructor
public class ItemProcessorConfig {

    private final JobRepository jobRepository;
		private final PlatformTransactionManager platformTransactionManager;


    @Bean
    public Job itemProcessorJob() {
        return new JobBuilder("itemProcessorJob", jobRepository)
                .incrementer(new RunIdIncrementer())
                .start(this.itemProcessorStep())
                .build();
    }

    @Bean
    public Step itemProcessorStep() {
        return new StepBuilder("itemProcessorStep", jobRepository)
                .<Person, Person>chunk(10)
                .reader(itemReader())
                .processor(itemProcessor())
                .writer(itemWriter())
                .build();
    }

    private ItemWriter<? super Person> itemWriter() {
        return items -> items.forEach(x -> log.info("PERSON.ID : {}", x.getId()));
    }

    private ItemProcessor<? super Person, ? extends Person> itemProcessor() {

        return item -> {
            if(item.getId() % 2 == 0){
                return item;
            }
            return null;
        };

    }

    private ItemReader<? extends Person> itemReader() {
        return new CustomItemReader<>(getItems());
    }

    private List<Person> getItems() {

        ArrayList<Person> peoples = new ArrayList<>();

        for (int i = 0; i < 100; i++) {
            peoples.add(new Person(i+1, "test name" + i, "test age", "test address"));
        }

        return peoples;
    }

}
