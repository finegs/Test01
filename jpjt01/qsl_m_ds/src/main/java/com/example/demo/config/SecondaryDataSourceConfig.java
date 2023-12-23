package com.example.demo.config;

import jakarta.persistence.EntityManagerFactory;
import javax.sql.DataSource;

import com.zaxxer.hikari.HikariDataSource;

import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.boot.autoconfigure.jdbc.DataSourceProperties;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.boot.orm.jpa.EntityManagerFactoryBuilder;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.data.jpa.repository.config.EnableJpaRepositories;
import org.springframework.orm.jpa.JpaTransactionManager;
import org.springframework.orm.jpa.LocalContainerEntityManagerFactoryBean;
import org.springframework.transaction.PlatformTransactionManager;
import org.springframework.transaction.annotation.EnableTransactionManagement;

import static com.example.demo.DemoConstants.*;

@Configuration
@EnableTransactionManagement
@EnableJpaRepositories(
        entityManagerFactoryRef = ENTITY_MANAGER_FACTORY_SECONDARY,
        transactionManagerRef = TRANSACTION_MANAGER_SECONDARY,
        basePackages = { "com.example.demo.secondary.repository" }
)
public class SecondaryDataSourceConfig {
    
    @Bean(name = PROPERTIES_DATASOURCE_SECONDARY)
    @ConfigurationProperties(PROPERTIES_DATASOURCE_SECONDARY)
    public DataSourceProperties secondaryDataSourceProperties() {
        return new DataSourceProperties();
    }

    @Bean(name = DATASOURCE_SECONDARY)
    @ConfigurationProperties(PROPERTIES_DATASOURCE_SECONDARY)
		public DataSource secondaryDataSource(
				@Qualifier(PROPERTIES_DATASOURCE_SECONDARY) DataSourceProperties dataSourceProperties) {
        return dataSourceProperties.initializeDataSourceBuilder().type(HikariDataSource.class).build();
    }

    @Bean(name = ENTITY_MANAGER_FACTORY_SECONDARY)
    public LocalContainerEntityManagerFactoryBean secondaryEntityManagerFactory(
				EntityManagerFactoryBuilder builder,
				@Qualifier(DATASOURCE_SECONDARY) DataSource dataSource) {
        return builder
						.dataSource(dataSource)
						.packages("com.example.demo.secondary.model")
						.persistenceUnit(ENTITY_MANAGER_SECONDARY)
						.build();
    }

    @Bean(name = TRANSACTION_MANAGER_SECONDARY)
		public PlatformTransactionManager secondaryTransactionManager(
				@Qualifier(ENTITY_MANAGER_FACTORY_SECONDARY) EntityManagerFactory entityManagerFactory) {
        return new JpaTransactionManager(entityManagerFactory);
    }
}
