package net.m8m.batchdemo;


import javax.sql.DataSource;

import org.springframework.batch.core.configuration.annotation.EnableBatchProcessing;
import org.springframework.batch.core.step.builder.StepBuilder;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Configuration;

@EnableBatchProcessing
@Configuration
public class BatchDemoConfig {
	@Autowired
	private DataSource jobBuilderFactory;

	@Autowired
	private StepBuilder stepBuilder;


}
