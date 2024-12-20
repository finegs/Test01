package com.example.examplebatch.part1;


import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.batch.core.Job;
import org.springframework.batch.core.Step;
import org.springframework.batch.core.job.builder.JobBuilder;
import org.springframework.batch.core.launch.support.RunIdIncrementer;
import org.springframework.batch.core.repository.JobRepository;
import org.springframework.batch.core.step.builder.StepBuilder;
import org.springframework.batch.repeat.RepeatStatus;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.transaction.PlatformTransactionManager;


@Configuration
@Slf4j
@RequiredArgsConstructor
public class HelloConfiguration {

		private final JobRepository jobRepository;
		private final PlatformTransactionManager platformTransactionManager;


    @Bean
    public Job helloJob() {
        return new JobBuilder("helloJob", jobRepository)
                .incrementer(new RunIdIncrementer())
                .start(helloStep())
                .build();
    }

    @Bean
    public Step helloStep(){
        return new StepBuilder("helloStep", jobRepository)
                .tasklet((contribution, chunkContext) -> {
                    log.info("Hello Spring Batch");
                    return RepeatStatus.FINISHED;
                }, platformTransactionManager)
                .build();
    }

}
