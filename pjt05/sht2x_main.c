#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "wiringPi.h"
#include "wiringPiI2C.h"

#include "sht2x.h"

char* getTimestamp() {
			static char* buf;
			static size_t buf_len;

			struct timespec ts;
			struct tm tm;
			struct tm* rtm;
		if(!buf) {
				buf_len = strlen("2019-12-31 11:59:59.123456789") + 1;
				buf = (char*)malloc(sizeof(char)*buf_len);
				memset(buf, '\0', buf_len);
		}

	clock_gettime(CLOCK_REALTIME, &ts);

#ifdef USE_LOCAL_TIME
	rtm = localtime_r (&ts.tv_sec, &tm);
#else
	rtm = gmtime_r (&ts.tv_sec, &tm);
#endif

	strftime(buf, buf_len, "%Y-%m-%d %H:%M:%S", rtm);
	sprintf(buf+19, ".%09ld", ts.tv_nsec);
	return buf;
}

// char* timestamp(char* ts) {
	// timeval curTime;
	// gettimeofday(&curTime, NULL);
	// int milli = curTime.tv_usec / 1000;
// 
	// char buffer [80];
	// strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", localtime(&curTime.tv_sec));
// 
	// char currentTime[84] = "";
	// sprintf(ts, "%s:%03d", buffer, milli);
	// return ts;
	// printf("current time: %s \n", currentTime);
// }


int main ()
{
	wiringPiSetup();
	int fd = wiringPiI2CSetup(SHT2x_I2C_ADDR);
	if ( 0 > fd )
	{
		fprintf (stderr, "Unable to open I2C device: %s\n", strerror (errno));
		exit (-1);
	}
	
	while(1) {
		usleep(3000*1000);
		printf("%s\tTemp:%5.2fC, Humidity:%5.2f%%RH\n", getTimestamp(), getTemperature(fd), getHumidity(fd));
		// printf("%5.2f%%rh\n", getHumidity(fd));
	}
	
	return 0;
}
