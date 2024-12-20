package com.example.mybatch;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Order;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.TestMethodOrder;
import org.junit.jupiter.api.MethodOrderer.OrderAnnotation;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
@TestMethodOrder(OrderAnnotation.class)
class DemoApplicationTests {


	@Test
	@Order(1)
	void contextLoads() {
		System.out.println("contextLoads is executed");
	}

	@Test
	@Order(2)
	void testFalse() {
		int a = 1;
		int b = 2;
		assertFalse(a==b, "a==b is not false");
	}

	@Test
	@Order(3)
	void testTrue() {
		int a = 1;
		int b = 1;
		assertTrue(a==b, "a==b is not true");
	}
}
