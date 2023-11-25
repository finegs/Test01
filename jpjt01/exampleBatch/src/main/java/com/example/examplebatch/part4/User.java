package com.example.examplebatch.part4;

import com.example.examplebatch.part5.Orders;
import lombok.Builder;
import lombok.Getter;
import lombok.NoArgsConstructor;

import jakarta.persistence.*;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

@Getter
@Entity
@Builder
@NoArgsConstructor
public class User {


    @Id
    @GeneratedValue(strategy = jakarta.persistence.GenerationType.IDENTITY)
    private Long id;

    private String name;

    @Enumerated(jakarta.persistence.EnumType.STRING)
    private Level level = Level.NORMAL;

    @OneToMany(cascade = CascadeType.PERSIST, fetch = FetchType.EAGER)
    @JoinColumn(name = "user_id")
    private List<Orders> orders = new ArrayList<>();

    private LocalDate updatedDate;

    @Builder
    public User(String name, List<Orders> orders) {
        this.name = name;
        this.orders = orders;
    }

    public void levelUp() {
        this.level = Level.getNextLevel(this.getTotalAmount());
        this.updatedDate = LocalDate.now();
    }

    private int getTotalAmount() {
        return orders.stream().mapToInt(Orders::getAmount).sum();
    }

    public boolean availableLevelUp() {
        return Level.availableLevelUp(this.getLevel(), this.getTotalAmount());
    }
}
