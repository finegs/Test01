package com.example.demo.config;

import jakarta.persistence.EntityManagerFactory;
import javax.sql.DataSource;

import com.zaxxer.hikari.HikariDataSource;

import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.boot.autoconfigure.jdbc.DataSourceProperties;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Primary;
import org.springframework.data.jpa.repository.config.EnableJpaRepositories;
import org.springframework.orm.jpa.JpaTransactionManager;
import org.springframework.orm.jpa.JpaVendorAdapter;
import org.springframework.orm.jpa.LocalContainerEntityManagerFactoryBean;
import org.springframework.orm.jpa.vendor.HibernateJpaVendorAdapter;
import org.springframework.transaction.PlatformTransactionManager;
import org.springframework.transaction.annotation.EnableTransactionManagement;

import static com.example.demo.DemoConstants.*;

import java.util.HashMap;

@Configuration
@EnableTransactionManagement
@EnableJpaRepositories(
        entityManagerFactoryRef = ENTITY_MANAGER_FACTORY_PRIMARY,
        transactionManagerRef = TRANSACTION_MANAGER_PRIMARY,
        basePackages = { "com.example.demo.primary.repository" }
)
public class PrimaryDataSourceConfig {


	@Bean(name = PROPERTIES_HIBERNATE_PRIMARY)
	@ConfigurationProperties(CONF_PATH_HIBERNATE_PRIMARY)
	public HashMap<String, Object> primaryHibernatePropertyMap() {
			return new HashMap<String, Object>();
	}

    
	@Primary
	@Bean(name = PROPERTIES_DATASOURCE_PRIMARY)
	@ConfigurationProperties(PROPERTIES_DATASOURCE_PRIMARY)
	public DataSourceProperties primaryDataSourceProperties() {
			return new DataSourceProperties();
	}

	@Primary
	@Bean(name = DATASOURCE_PRIMARY)
	@ConfigurationProperties(PROPERTIES_DATASOURCE_PRIMARY)
	public DataSource primaryDataSource(
			@Qualifier(PROPERTIES_DATASOURCE_PRIMARY) DataSourceProperties dataSourceProperties) {
			return dataSourceProperties.initializeDataSourceBuilder().type(HikariDataSource.class).build();
	}

	@Primary
	@Bean(name = ENTITY_MANAGER_FACTORY_PRIMARY)
	public LocalContainerEntityManagerFactoryBean primaryEntityManagerFactory(
			@Qualifier(DATASOURCE_PRIMARY) DataSource dataSource) {
			LocalContainerEntityManagerFactoryBean entityManagerFactoryBean = new LocalContainerEntityManagerFactoryBean();
			entityManagerFactoryBean.setDataSource(dataSource);
			entityManagerFactoryBean.setPersistenceUnitName(ENTITY_MANAGER_PRIMARY);
			entityManagerFactoryBean.setPackagesToScan("com.example.demo.primary.model");

			JpaVendorAdapter vendorAdapter = new HibernateJpaVendorAdapter();
			entityManagerFactoryBean.setJpaVendorAdapter(vendorAdapter);
			entityManagerFactoryBean.setJpaPropertyMap(primaryHibernatePropertyMap());
			return entityManagerFactoryBean;
	}

	@Primary
	@Bean(name = TRANSACTION_MANAGER_PRIMARY)
	public PlatformTransactionManager primaryTransactionManager(
			@Qualifier(ENTITY_MANAGER_FACTORY_PRIMARY) EntityManagerFactory entityManagerFactory) {
			return new JpaTransactionManager(entityManagerFactory);
	}
}
