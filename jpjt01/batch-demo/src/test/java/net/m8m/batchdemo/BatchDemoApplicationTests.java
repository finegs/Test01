package net.m8m.batchdemo;

import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

import java.util.Arrays;
import java.util.List;
import java.util.concurrent.atomic.AtomicInteger;

import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.TestPropertySource;

@SpringBootTest
@TestPropertySource(properties="app.scheduling.enable=false")
class BatchDemoApplicationTests {

	@Test
	void contextLoads() {
		List<String> a = Arrays.asList("aa","bbb", "ccc cc");
		AtomicInteger idx = new AtomicInteger(0);
		a.stream().filter(s->  s.contains("aa")).forEach(s -> System.out.printf("[%d]:%s\n", idx.getAndIncrement(), s));
		int expectedValue = 1;
		assertTrue(idx.get() == expectedValue, 
				String.format("filtered expected : %d, value : %d", expectedValue, idx.get()));
	}

	@Test
	void test_stream_filter() {
		List<String> a = Arrays.asList("aa","bbb", "ccc cc");
		AtomicInteger idx = new AtomicInteger(0);
		a.stream().filter(s->  s.contains("aa")).forEach(s -> System.out.printf("[%d]:%s\n", idx.getAndIncrement(), s));
		int expectedValue = 2;
		assertFalse(idx.get() == expectedValue, 
				String.format("filtered expected : %d, value : %d", expectedValue, idx.get()));
	}

	@Test
	void failTest() {
		int a =1;
		int b =2;
		assertFalse(a==b, "1==2 is not equal");
	}
	@Test
	void trueTest() {
		int a =1;
		int b =1;
		assertTrue(a==b, "1==1 is not equal");
	}

}
