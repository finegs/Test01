package com.example.examplebatch.part5;

import lombok.Builder;
import lombok.Getter;
import lombok.NoArgsConstructor;

import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.Id;
import java.time.LocalDate;

@NoArgsConstructor
@Getter
@Entity
public class Orders {

    @Id
    @GeneratedValue(strategy = jakarta.persistence.GenerationType.IDENTITY)
    private Long id;
    private String name;
    private int amount;
    private LocalDate createdDate;

    @Builder
    private Orders(String name, int amount, LocalDate createdDate) {
        this.name = name;
        this.amount = amount;
        this.createdDate = createdDate;
    }
}
