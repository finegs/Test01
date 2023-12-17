package com.example.demo.primary.model;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import jakarta.persistence.Table;

@Entity
@Table(schema = "SCHEMA_NAME", name="TEST_ENTITY")
public class TestEntity {
    @Id
    @Column(name="ID")
    private String id;

    @Column(name="COLUMN")
    private String column;
}
