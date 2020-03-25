#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define unsigned int uint4

uint4 RESOLUTION_12BITS = 0b00000000;


int main() {

	int fd;
	int i,cnt;
	int channel = 1;
	int i2caddr = 0x40;
	int prev, a2dVal;

	printf("[D] Test SHT20\n");

	if((fd = wiringPiI2CSetup(i2caddr))<0) {
		printf("[E] wiringPiI2CSetup failed:\n");
	}

	cnt = 0;
	while(1) {
		wiringPiI2CWrite(fd, 0x00|channel);

		prev = wiringPiI2CRead(fd);
		printf("[%d]\t[I] previous = %d, ", cnt, prev);

		val  = wiringPiI2CRead(fd);
		printf("\t[I] 2nd val  = %d, ", val); 

		delay(1000);
		cnt++;
	}


	return 0;
}
