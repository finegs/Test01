package com.example.examplebatch.part4;

import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.batch.core.JobExecution;
import org.springframework.batch.core.JobExecutionListener;

import java.time.Duration;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.Period;
import java.time.temporal.ChronoField;
import java.util.Collection;
import java.util.Optional;

@RequiredArgsConstructor
@Slf4j
public class LevelUpJobExecutionListener implements JobExecutionListener {

    private final UserRepository userRepository;

    @Override
    public void beforeJob(JobExecution jobExecution) {
    }

    @Override
    public void afterJob(JobExecution jobExecution) {
			Collection<User> users = userRepository.findAllByUpdatedDate(LocalDate.now());

			// long usec = jobExecution.getStartTime().until(jobExecution.getEndTime(), ChronoField.MILLI_OF_SECOND);
			Duration du = Duration.between(jobExecution.getStartTime(), jobExecution.getEndTime());
			long days = du.get(ChronoField.EPOCH_DAY);
			long usecs = du.get(ChronoField.MICRO_OF_DAY);
			// Period executionTime = Period.between(jobExecution.getStartTime(), jobExecution.getEndTime());

			// long elapsedMills = executionTime.get(ChronoField.MICRO_OF_SECOND);

			// long e = Optional.ofNullable(jobExecution.getEndTime()).map(ldt -> ldt.getLong(ChronoField.MICRO_OF_SECOND)).orElse(0L);
			// long s = Optional.ofNullable(jobExecution.getStartTime()).map(ldt -> ldt.getLong(ChronoField.MICRO_OF_SECOND)).orElse(0L);
			Duration<ClockUnit> duration = Duration.of(du.getSeconds(), ClockUnit.SECONDS); // input in seconds only .with(Duration.STD_CLOCK_PERIOD); // performs normalization to h:mm:ss-structure
			String strHHMMSS = Duration.formatter(ClockUnit.class, "+##h:mm:ss").format(duration);

			log.info(" batch time : {}.{%06d} \", total data processed : {} user", 
					strHHMMSS, 
					du.get(ChronoField.MICRO_OF_SECOND),  users.size());
    }
}
