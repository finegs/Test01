package com.example.demo.config.querydsl;

import jakarta.persistence.EntityManager;
import jakarta.persistence.PersistenceContext;

import org.springframework.data.jpa.repository.support.QuerydslRepositorySupport;
import org.springframework.stereotype.Repository;

import static com.example.demo.DemoConstants.*;

@Repository
public abstract class SecondaryQuerydslRepositorySupport extends QuerydslRepositorySupport {

    public SecondaryQuerydslRepositorySupport(Class<?> domainClass) {
        super(domainClass);
    }

    @Override
    @PersistenceContext(unitName = ENTITY_MANAGER_SECONDARY)
    public void setEntityManager(EntityManager entityManager) {
        super.setEntityManager(entityManager);
    }
    
}
