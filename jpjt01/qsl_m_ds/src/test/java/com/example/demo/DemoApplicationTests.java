package com.example.demo;

import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;

import com.example.demo.config.PrimaryDataSourceConfig;
import com.example.demo.config.QuerydslConfig;
import com.example.demo.config.SecondaryDataSourceConfig;

import lombok.extern.slf4j.Slf4j;

@Slf4j
@SpringBootTest
(
 classes = {
	 PrimaryDataSourceConfig.class,
	 SecondaryDataSourceConfig.class,
	 QuerydslConfig.class
 }
)
class DemoApplicationTests {

	@Test
	void contextLoads() {
		log.debug("DemoApplicationTests.contextLoads() is executed.");
	}


	@Test
	public void test_dijat() {
		
	}

}
