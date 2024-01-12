package com.example.examplebatch.part3;

import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.batch.core.Job;
import org.springframework.batch.core.Step;
import org.springframework.batch.core.StepExecution;
import org.springframework.batch.core.configuration.annotation.JobScope;
import org.springframework.batch.core.configuration.annotation.StepScope;
import org.springframework.batch.core.job.builder.JobBuilder;
import org.springframework.batch.core.launch.support.RunIdIncrementer;
import org.springframework.batch.core.repository.JobRepository;
import org.springframework.batch.core.step.builder.StepBuilder;
import org.springframework.batch.core.step.tasklet.Tasklet;
import org.springframework.batch.item.ItemProcessor;
import org.springframework.batch.item.ItemReader;
import org.springframework.batch.item.ItemWriter;
import org.springframework.batch.item.support.ListItemReader;
import org.springframework.batch.repeat.RepeatStatus;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.transaction.PlatformTransactionManager;
import org.springframework.util.StringUtils;

import java.util.ArrayList;
import java.util.List;

@Configuration
@Slf4j
@RequiredArgsConstructor
public class ChunkProcessingConfig {

	private final JobRepository jobRepository;
	private final PlatformTransactionManager platformTransactionManager;

    @Bean
    public Job chunkJob(){
        return new JobBuilder("chunkProcessingJob", jobRepository)
                .incrementer(new RunIdIncrementer())
                .start(this.taskBaseStep(jobRepository))
                .next(this.chunkBaseStep(null))
                .build();
    }

    @Bean
    @JobScope
    public Step chunkBaseStep(@Value("#{jobParameters[chunkSize]}") String chunkSize){
        return new StepBuilder("chunkBaseStep", jobRepository)
                .<String, String>chunk(StringUtils.hasText(chunkSize) ? Integer.parseInt(chunkSize) : 10, platformTransactionManager)
                .reader(itemReader())
                .processor(itemProcessor())
                .writer(itemWriter())
                .build();
    }

    private ItemWriter<? super String> itemWriter() {
        return items -> log.info("chunk item size: {}", items.size());
    }


    private ItemReader<String> itemReader() {
        return new ListItemReader<>(getItems());
    }

    private ItemProcessor<String, String> itemProcessor() {
        return item -> item + ", Spring Batch";
    }


    @Bean
    public Step taskBaseStep(JobRepository jobRepository){
        return new StepBuilder("taskBaseStep", jobRepository)
                .tasklet(this.tasklet(null), platformTransactionManager)
                .build();
    }

    @Bean
    @StepScope
    public Tasklet tasklet(@Value("#{jobParameters[chunkSize]}") String value) {
        return (contribution, chunkContext) -> {
            List<String> items = getItems();
            StepExecution stepExecution = contribution.getStepExecution();

            int chunkSize = StringUtils.hasText(value) ? Integer.parseInt(value) : 10;

            int fromIndex = java.lang.Math.toIntExact(stepExecution.getReadCount());
            int toIndex = java.lang.Math.toIntExact(fromIndex + chunkSize);

            if(fromIndex >= items.size()){
                return RepeatStatus.FINISHED;
            }

            List<String> subList = items.subList(fromIndex, toIndex);
            stepExecution.setReadCount(toIndex);

            log.info("task item size: {}", subList.size());

            return RepeatStatus.CONTINUABLE;
        };
    }

    private List<String> getItems() {

        ArrayList<String> items = new ArrayList<>();

        for (int i = 0; i < 100; i++) {
            items.add(i + " Hello");
        }

        return items;
    }

}
