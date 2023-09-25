package com.example.mybatch;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
class DemoApplicationTests {

	@Test
	void contextLoads() {
		System.out.println("contextLoads is executed");
	}

	@Test
	void testFalse() {
		int a = 1;
		int b = 2;
		assertFalse(a==b, "a==b is not false");
	}

	@Test
	void testTrue() {
		int a = 1;
		int b = 1;
		assertTrue(a==b, "a==b is not true");
	}
}
