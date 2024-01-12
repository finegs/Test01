package com.example.demo.secondary.model;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.Table;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import lombok.experimental.Accessors;

/**
* UserEntity
*/
@Entity
@Table(schema="MY_SCHEMA", name="T_USER")
@Accessors(fluent=true, chain=true)
@Getter
@Setter
@NoArgsConstructor
public class UserEntity {
	
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	@Column(name="USER_ID")
	private Long id;

	@Column(name="USER_NAME")
	private String name;

	@Column(name="USER_KNICK_NAME")
	private String knickName;
}
