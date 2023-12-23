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
import org.springframework.context.annotation.Primary;
import org.springframework.data.jpa.repository.config.EnableJpaRepositories;
import org.springframework.orm.jpa.JpaTransactionManager;
import org.springframework.orm.jpa.LocalContainerEntityManagerFactoryBean;
import org.springframework.transaction.PlatformTransactionManager;
import org.springframework.transaction.annotation.EnableTransactionManagement;

import static com.example.demo.DemoConstants.*;

@Configuration
@EnableTransactionManagement
@EnableJpaRepositories(
        entityManagerFactoryRef = ENTITY_MANAGER_FACTORY_PRIMARY,
        transactionManagerRef = TRANSACTION_MANAGER_PRIMARY,
        basePackages = { "com.example.demo.primary.repository" }
)
public class PrimaryDataSourceConfig {
    
    @Primary
    @Bean
    @ConfigurationProperties(PROPERTIES_DATASOURCE_PRIMARY)
    public DataSourceProperties primaryDataSourceProperties() {
        return new DataSourceProperties();
    }

    @Primary
    @Bean
    @ConfigurationProperties(DATASOURCE_PRIMARY)
    public DataSource primaryDataSource(
				@Qualifier(PROPERTIES_DATASOURCE_PRIMARY) DataSourceProperties dataSourceProperties) {
        return dataSourceProperties.initializeDataSourceBuilder().type(HikariDataSource.class).build();
    }

    @Primary
    @Bean(name = ENTITY_MANAGER_FACTORY_PRIMARY)
    public LocalContainerEntityManagerFactoryBean primaryEntityManagerFactory(
				EntityManagerFactoryBuilder builder, 
				@Qualifier(DATASOURCE_PRIMARY) DataSource dataSource) {
        return builder
							.dataSource(dataSource)
							.packages("com.example.demo.primary.model")
							.persistenceUnit(ENTITY_MANAGER_PRIMARY)
							.build();
    }

    @Primary
    @Bean(name = TRANSACTION_MANAGER_PRIMARY)
    public PlatformTransactionManager primaryTransactionManager(
				@Qualifier(ENTITY_MANAGER_FACTORY_PRIMARY) EntityManagerFactory entityManagerFactory) {
        return new JpaTransactionManager(entityManagerFactory);
    }
}
