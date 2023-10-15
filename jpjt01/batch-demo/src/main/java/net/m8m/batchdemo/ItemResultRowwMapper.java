package net.m8m.batchdemo;

import java.sql.ResultSet;
import java.sql.SQLException;

import org.springframework.jdbc.core.RowMapper;

import net.m8m.batchdemo.model.Item;

public class ItemResultRowwMapper  implements RowMapper<Item>{

	@Override
	public Item mapRow(ResultSet rs, int rowNum) throws SQLException {
		// throw new UnsupportedOperationException("Unimplemented method 'mapRow'");
		Item item = new Item();	
		return item;
	}
}
