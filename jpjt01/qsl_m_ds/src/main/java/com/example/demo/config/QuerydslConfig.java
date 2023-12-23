package com.example.demo.config;

import jakarta.persistence.EntityManager;
import jakarta.persistence.PersistenceContext;

import com.querydsl.jpa.impl.JPAQueryFactory;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import static com.example.demo.DemoConstants.*;

@Configuration
public class QuerydslConfig {
    @PersistenceContext(unitName = ENTITY_MANAGER_PRIMARY)
    EntityManager entityManager1;

    @PersistenceContext(unitName = ENTITY_MANAGER_SECONDARY)
    EntityManager entityManager2;

    @Bean
    public JPAQueryFactory primaryQueryFactory() {
        return new JPAQueryFactory(entityManager1);
    }

    @Bean(name = QUERY_FACTORY_SECONDARY)
    public JPAQueryFactory secondaryQueryFactory() {
        return new JPAQueryFactory(entityManager2);
    }
}
