package net.m8m.batchdemo.model;

import lombok.*;


@Data
@ToString(includeFieldNames = true)
public class Item {
	private Long id;
	private String name;
	private String desc;
	private String value;
	private String[] tags;
}
