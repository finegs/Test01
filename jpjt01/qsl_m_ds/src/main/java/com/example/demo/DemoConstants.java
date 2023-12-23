package com.example.demo;

public interface DemoConstants {
	public static String PROPERTIES_DATASOURCE_PRIMARY = "primary.datasource";
	public static String PROPERTIES_DATASOURCE_SECONDARY = "secondary.datasource";

	public static String PROPERTIES_HIBERNATE_PRIMARY = "primaryHibernateProperties";
	public static String PROPERTIES_HIBERNATE_SECONDARY = "secondaryHibernatePropertyMap";

	public static String CONF_PATH_HIBERNATE_DEFAULT = "spring.jpa.hibernate";
	public static String CONF_PATH_HIBERNATE_PRIMARY = "primary.hibernate";
	public static String CONF_PATH_HIBERNATE_SECONDARY = "secondary.hibernate";

	public static String ENTITY_MANAGER_FACTORY_PRIMARY = "primaryEntityManagerFactory";
	public static String ENTITY_MANAGER_FACTORY_SECONDARY = "secondaryEntityManagerFactory";

	public static String TRANSACTION_MANAGER_PRIMARY = "primaryTransactionManager";
	public static String TRANSACTION_MANAGER_SECONDARY = "secondaryTransactionManager";

	public static String ENTITY_MANAGER_PRIMARY = "primaryEntityManager";
	public static String ENTITY_MANAGER_SECONDARY = "secondaryEntityManager";

	public static String DATASOURCE_DEFAULT = "dataSource";
	public static String DATASOURCE_PRIMARY = "primaryDataSource";
	public static String DATASOURCE_SECONDARY = "secondaryDataSource";

	public static String QUERY_FACTORY_PRIMARY = "primaryQueryFactory";
	public static String QUERY_FACTORY_SECONDARY = "secondaryQueryFactory";

}
