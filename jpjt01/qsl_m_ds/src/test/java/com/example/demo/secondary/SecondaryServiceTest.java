package com.example.demo.secondary;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.boot.autoconfigure.ImportAutoConfiguration;
import org.springframework.boot.test.autoconfigure.jdbc.AutoConfigureTestDatabase;
import org.springframework.boot.test.autoconfigure.orm.jpa.DataJpaTest;

import com.example.demo.config.PrimaryDataSourceConfig;
import com.example.demo.config.QuerydslConfig;
import com.example.demo.config.SecondaryDataSourceConfig;
import com.querydsl.jpa.impl.JPAQueryFactory;

import jakarta.persistence.EntityManager;
import jakarta.persistence.PersistenceContext;

import lombok.extern.slf4j.Slf4j;

import org.springframework.boot.test.autoconfigure.jdbc.AutoConfigureTestDatabase.Replace;
import static com.example.demo.DemoConstants.*;

@Slf4j
@AutoConfigureTestDatabase(replace = Replace.NONE)
@DataJpaTest
@ImportAutoConfiguration(
	classes = {
							SecondaryDataSourceConfig.class,
							PrimaryDataSourceConfig.class,
							QuerydslConfig.class
						}
)
public class SecondaryServiceTest {

	@PersistenceContext(name = ENTITY_MANAGER_PRIMARY)
 	EntityManager primaryEntityManager;

	@PersistenceContext(name = ENTITY_MANAGER_SECONDARY)
 	EntityManager secondaryEntityManager;

	@Autowired
	@Qualifier(QUERY_FACTORY_PRIMARY)
	JPAQueryFactory primaryQueryFactory;
	
	@Autowired
	@Qualifier(QUERY_FACTORY_SECONDARY)
	JPAQueryFactory secondaryQueryFactory;

	@Test
	public void test_primaryEntityManager_is_not_null() {
		assertNotNull(primaryEntityManager);	
		log.debug("SecondaryDataSourceConfig.test_primaryEntityManager_is_not_null() is executed.");
	}

	@Test void test_secondaryEntityManager_is_not_null() {
		assertNotNull(secondaryEntityManager);
		log.debug("SecondaryDataSourceConfig.test_secondaryEntityManager_is_not_null() is executed.");
	}

	
}
