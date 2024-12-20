package net.m8m.batchdemo;


import javax.sql.DataSource;

import org.springframework.batch.core.configuration.annotation.EnableBatchProcessing;
import org.springframework.batch.core.repository.JobRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Configuration;
import org.springframework.transaction.PlatformTransactionManager;

@EnableBatchProcessing
@Configuration
public class BatchDemoConfig {

	@Autowired
	private DataSource dataSource;

	@Autowired
	private JobRepository jobRepository;

	@Autowired
	private PlatformTransactionManager platformTransanctionManager;

}
