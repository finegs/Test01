package net.m8m.batchdemo;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

import java.util.Arrays;
import java.util.List;
import java.util.concurrent.atomic.AtomicInteger;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.Order;
import org.junit.jupiter.api.TestMethodOrder;
import org.junit.jupiter.api.MethodOrderer.OrderAnnotation;
import org.springframework.boot.test.context.SpringBootTest;

import lombok.extern.slf4j.Slf4j;
 // @SpringBootTest
 @Slf4j
 @TestMethodOrder(OrderAnnotation.class)
class BatchDemoApplicationTests {

	List<String> arr = Arrays.asList("aa","bbb", "ccc cc");

	@Test
	@Order(1)
	void contextLoads() {
	assertTrue(true, "contextLoads");	
		// List<String> arr = Arrays.asList("aa","bbb", "ccc cc");
		// AtomicInteger idx = new AtomicInteger(0);
		//
		// arr.stream().filter(s->  s.contains("aa")).forEach(s -> System.out.printf("[%d]:%s\n", idx.getAndIncrement(), s));
		// int expectedValue = 1;
		// assertTrue(idx.get() == expectedValue, 
		// 		String.format("filtered expected : %d, value : %d", expectedValue, idx.get()));
	}

	@Test
	@Order(2)
	void test_stream_filter() {
		AtomicInteger idx = new AtomicInteger(0);
		arr.stream()
			.filter(s->  s.contains("aa"))
			.forEach(s -> System.out.printf("[%d]:%s\n", idx.getAndIncrement(), s));
		int expectedValue = 2;
		assertFalse(idx.get() == expectedValue, 
				String.format("filtered expected : %d, value : %d", expectedValue, idx.get()));
	}

	@Test
	@Order(3)
	void failTest() {
		int a =1;
		int b =2;
		assertFalse(a==b, "1==2 is not equal");
	}

	@Test
	@Order(4)
	void trueTest() {
		int a =1;
		int b =1;
		assertTrue(a==b, "1==1 is equal");
	}

	@Test
	@Order(5)
	void stream_test() {
		List<Integer> aa = Arrays.asList(1,2,3,4,5);

		var sum_of_aa = aa.stream().map(a->a.intValue()).reduce(0, (a,b) ->  a + b);

		assertEquals(sum_of_aa, 15);

		log.info("stream_test : {}", sum_of_aa);
	}
}
