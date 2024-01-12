package com.example.demo.config;

import jakarta.persistence.EntityManager;
import jakarta.persistence.PersistenceContext;
import lombok.RequiredArgsConstructor;

import com.querydsl.jpa.impl.JPAQueryFactory;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Primary;
import static com.example.demo.DemoConstants.*;

@Configuration
@RequiredArgsConstructor
public class QuerydslConfig {
    @PersistenceContext(unitName = ENTITY_MANAGER_PRIMARY)
    private final EntityManager primaryEntityManager;

    @PersistenceContext(unitName = ENTITY_MANAGER_SECONDARY)
    private final EntityManager secondaryEntityManager;

    @Bean(name = QUERY_FACTORY_PRIMARY)
		@Primary
		public JPAQueryFactory primaryQueryFactory() { 
			return new JPAQueryFactory(primaryEntityManager);
    }

    @Bean(name = QUERY_FACTORY_SECONDARY)
    public JPAQueryFactory secondaryQueryFactory() {
        return new JPAQueryFactory(secondaryEntityManager);
    }
}
