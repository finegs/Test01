package com.example.demo.config.querydsl;

import jakarta.persistence.EntityManager;
import jakarta.persistence.PersistenceContext;

import org.springframework.data.jpa.repository.support.QuerydslRepositorySupport;
import org.springframework.stereotype.Repository;

import static com.example.demo.DemoConstants.*;

@Repository
public abstract class PrimaryQuerydslRepositorySupport extends QuerydslRepositorySupport {

    public PrimaryQuerydslRepositorySupport(Class<?> domainClass) {
        super(domainClass);
    }

    @Override
    @PersistenceContext(unitName = ENTITY_MANAGER_PRIMARY)
    public void setEntityManager(EntityManager entityManager) {
        super.setEntityManager(entityManager);
    }
    
}
