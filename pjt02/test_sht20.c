#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define unsigned int uint4

uint4 RESOLUTION_12BITS = 0b00000000;


int main() {

<<<<<<< HEAD
	int fd;
	int i,cnt;
	int channel = 1;
	int i2caddr = 0x40;
	int prev, a2dVal;

	printf("[D] Test SHT20\n");
=======
	SHT20_SoftReset();

	while(1)
	{
		//SHT20 0x80 //SHT20 Temp Humidity sensor ID
		SHT20_read(SHT20, SHT20_TEMPERATURE, &dat); //SHT20_TEMPERATURE 0xE3 //Measure Temperature under Hole Mode
		SHT20_Digit(0xC2, &dat, 'T'); //SHT20_HUMIDITY 0xE5 //Measure Humidity under Hold Mode
	}
}


void SHT20_read(unsigned char chip, unsigned char addr, unsigned char * dat)
{
	TWCR = 0xA4;  // START       
	while(((TWCR & 0x80) == 0x00) || ((TWSR & 0xf8) != 0x08));
	TWDR = chip;  // SLA-W
	TWCR = 0x84;
	while(((TWCR & 0x80) == 0x00) || ((TWSR & 0xf8) != 0x18));

	TWDR = addr;
	TWCR = 0x84; // Temperature or Humidity
	while(((TWCR & 0x80) == 0x00) || ((TWSR & 0xf8) != 0x28));

	TWCR = 0x94;

	TWCR = 0xA4;                    // RE-START
	while(((TWCR & 0x80) == 0x00) || ((TWSR & 0xf8) != 0x10));

	TWDR = chip | 0x01;                    // SLA-R
	TWCR = 0xC4;//with ACK
	while(((TWCR & 0x80) == 0x00) || ((TWSR & 0xf8) != 0x40));

	TWCR = 0xC4;//with ACK
	while(((TWCR & 0x80) == 0x00) || ((TWSR & 0xf8) != 0x50));

	*dat = (unsigned char)TWDR;

	TWCR = 0xC4;//with ACK
	while(((TWCR & 0x80) == 0x00) || ((TWSR & 0xf8) != 0x50));

	dat++;
	*dat = (unsigned char)TWDR;

	TWCR = 0x84;//with NAK
	while(((TWCR & 0x80) == 0x00) || ((TWSR & 0xf8) != 0x58));

	dat++;
	*dat = (unsigned char)TWDR;
>>>>>>> 9b972e4e801f0158931ef43cae4dd1379d5be9c0

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
