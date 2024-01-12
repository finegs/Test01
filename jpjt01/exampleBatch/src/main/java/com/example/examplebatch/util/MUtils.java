package com.example.examplebatch.util;

import java.time.temporal.ChronoUnit;
import java.time.temporal.Temporal;;


public class MUtils {


	public static String formatDuration(Temporal from, Temporal to) {
			final StringBuilder builder = new StringBuilder();
			for (ChronoUnit unit : new ChronoUnit[]{YEARS, 
																							MONTHS, 
																							WEEKS, 
																							DAYS, 
																							HOURS, 
																							MINUTES, 
																							SECONDS}) {
					long amount = unit.between(from, to);
					if (amount == 0) {
							continue;
					}
					builder.append(' ')
									.append(amount)
									.append(' ')
									.append(unit.name().toLowerCase());
					from = from.plus(amount, unit);
			}
			return builder.toString().trim();
	}
}
