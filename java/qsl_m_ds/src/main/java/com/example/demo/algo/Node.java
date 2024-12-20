package com.example.demo.algo;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.experimental.Accessors;

/**
* Node
*/
@AllArgsConstructor
@NoArgsConstructor
@Accessors(fluent=true, chain=true)
@Getter
public class Node {
	private int idx;
	private int cost;
}
