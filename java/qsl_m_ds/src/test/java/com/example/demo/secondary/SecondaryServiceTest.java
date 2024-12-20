package com.example.demo.secondary;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.boot.autoconfigure.ImportAutoConfiguration;
import org.springframework.boot.test.autoconfigure.jdbc.AutoConfigureTestDatabase;
import org.springframework.boot.test.autoconfigure.orm.jpa.DataJpaTest;
import org.springframework.transaction.annotation.Transactional;

import com.example.demo.config.PrimaryDataSourceConfig;
import com.example.demo.config.QuerydslConfig;
import com.example.demo.config.SecondaryDataSourceConfig;
import com.example.demo.secondary.model.QUserEntity;
import com.example.demo.secondary.model.UserEntity;
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
	JPAQueryFactory qf1;
	
	@Autowired
	@Qualifier(QUERY_FACTORY_SECONDARY)
	JPAQueryFactory qf2;

	@Test
	public void test_primaryEntityManager_is_not_null() {
		assertNotNull(primaryEntityManager);	
		log.debug("SecondaryDataSourceConfig.test_primaryEntityManager_is_not_null() is executed.");
	}

	@Test
 	void test_secondaryEntityManager_is_not_null() {
		assertNotNull(secondaryEntityManager);
		log.debug("SecondaryDataSourceConfig.test_secondaryEntityManager_is_not_null() is executed.");
	}

	@Test
	@DisplayName("test_user_add_remove")
	@Transactional
	void test_user_add_remove() {
			QUserEntity que = QUserEntity.userEntity; 

			UserEntity ue = new UserEntity()
				.name("new user")
				.knickName("new knick name");

			// Insert 1 record
			qf2.insert(que)
				.columns(que.name, que.knickName)
				.values(ue.name(), ue.knickName())
				.execute();
			
			/*
			 		insert.set(survey.id, 5).set(survey.name, "5").addBatch();
			 		insert.set(survey.id, 6).set(survey.name, "6").addBatch();
			 		assertEquals(2, insert.execute());*
			 */

			// Test inserted
			assertEquals(qf2
					.select(que)
					.where(que.name.eq(ue.name()))
					.fetch()
					.size(),
					1);


			qf2.delete(que)
				.where(que.name.eq(ue.name()))
				.execute();

			// Test deleted
			assertEquals(qf2
					.select(que)
					.where(que.name.eq(ue.name()))
					.fetch()
					.size(),
					0);

			log.debug("SecondaryServiceTest.test_user_add_remove() is done.");

	}
}
