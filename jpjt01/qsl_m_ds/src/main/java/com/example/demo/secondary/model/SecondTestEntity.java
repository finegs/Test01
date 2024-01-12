package com.example.demo.secondary.model;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import jakarta.persistence.Table;

@Entity
@Table(schema = "SCHEMA_NAME", name="TEST_ENTITY_2")
public class SecondTestEntity {
    @Id
    @Column(name="ID")
    private String id;

    @Column(name="COLUMN")
    private String column;
}
