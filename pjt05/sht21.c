// ads1115b.c read pot on ANC1
// output value in volts exit program.
// uses one-shot mode
// pull up resistors in module caused problems
// used level translator - operated ADS1115 at 5V
// by Lewis Loflin lewis@bvu.net
// www.bristolwatch.com
// http://www.bristolwatch.com/rpi/ads1115.html

#include <stdio.h>
#include <string.h>
#include <sys/types.h> // open
#include <sys/stat.h>  // open
#include <fcntl.h>     // open
#include <unistd.h>    // read/write usleep
#include <stdlib.h>    // exit
#include <inttypes.h>  // uint8_t, etc
#include <sys/ioctl.h> // ioctl
#include <linux/i2c-dev.h> // I2C bus definitions
#include <unistd.h>

int fd;
// Note PCF8591 defaults to 0x48!
// int ads_address = 0x48;

// for SHT20
#define DEVICE_FILE_I2C_1  				"/dev/i2c-1"
#define SHT20_CMD_SOFTRESET 			0xFE
#define SHT20_CMD_TEMPERATURE_NO_HOLD 	0xF3
#define SHT20_CMD_HUMIDITY_NO_HOLD 		0xF5
#define STH20_STATUS_BIT_MASK 			0xFFFC
// (datasheet : typical=66, max=85)
// (datasheet : typical=22, max=29)
#define STH20_TEMPERATURE_WAITINTIME 	0.086
#define STH20_HUMIDITY_WAITINTIME 		0.030

int ads_address = 0x40;
int16_t val;

uint8_t writeBuf[3];
uint8_t readBuf[2];

float myfloat;

const float VPS = 4.096 / 32768.0; //volts per step

/*
The resolution of the ADC in single ended 
mode we have 15 bit rather than 16 bit resolution, 
the 16th bit being the sign of the differential reading.
*/
int sht20_reset(int fd);
int read_temperature(int fd, uint16_t* var);
int read_humidity(int fd, uint16_t* var);
int calc_checksum(uint8_t* b, size_t l);
int calc_temperature(uint8_t* b, size_t l, uint16_t* result);
int calc_humidity(uint8_t* b, size_t l, uint16_t* result);


int main() {
	int rc;
	int fd;

  // open device on /dev/i2c-1 
  // the default on Raspberry Pi B
  if ((fd = open(DEVICE_FILE_I2C_1, O_RDWR)) < 0) {
    printf("Error: Couldn't open device! file:%s, ec=%d\n", DEVICE_FILE_I2C_1, fd);
    exit (1);
  }

  // connect to ads1115 as i2c slave
  if ((rc = ioctl(fd, I2C_SLAVE, ads_address)) < 0) {
    printf("Error: Couldn't find device on address! %X, %u\n", ads_address, rc);
    exit (1);
  }

  uint16_t buf;

  sht20_reset(fd);

  memset(&buf, 0, 2);
  read_temperature(fd, &buf);
  printf("Temperature : %d\n", buf);

  memset(&buf, 0, 2);
  read_humidity(fd, &buf);
  printf("Humidity : %d\n", buf);

#ifdef USE_ADS1115
  // set config register and start conversion
  // ANC1 and GND, 4.096v, 128s/s
  writeBuf[0] = 1;    // config register is 1
  writeBuf[1] = 0b11010011; // bit 15-8 0xD3
  // bit 15 flag bit for single shot
  // Bits 14-12 input selection:
  // 100 ANC0; 101 ANC1; 110 ANC2; 111 ANC3
  // Bits 11-9 Amp gain. Default to 010 here 001 P19
  // Bit 8 Operational mode of the ADS1115.
  // 0 : Continuous conversion mode
  // 1 : Power-down single-shot mode (default)

  writeBuf[2] = 0b10000101; // bits 7-0  0x85
  // Bits 7-5 data rate default to 100 for 128SPS
  // Bits 4-0  comparator functions see spec sheet.

  // begin conversion
  if (write(fd, writeBuf, 3) != 3) {
    perror("Write to register 1");
    exit(-1);
  }

  // wait for conversion complete
  // checking bit 15
  do {
    if (read(fd, writeBuf, 2) != 2) {
      perror("Read conversion");
      exit(-1);
    }
  }
  while ((writeBuf[0] & 0x80) == 0);

  // read conversion register
  // write register pointer first
  readBuf[0] = 0;   // conversion register is 0
  if (write(fd, readBuf, 1) != 1) {
    perror("Write register select");
    exit(-1);
  }
  
  // read 2 bytes
  if (read(fd, readBuf, 2) != 2) {
    perror("Read conversion");
    exit(-1);
  }

  // convert display results
  val = readBuf[0] << 8 | readBuf[1];

  if (val < 0)   val = 0;

  myfloat = val * VPS; // convert to voltage

  printf("Values: HEX 0x%02x DEC %d reading %4.3f volts.\n",
         val, val, myfloat);
#endif  
  close(fd);

  return 0;
}

int sht20_reset(int fd) {

	int rc;
	uint8_t addr = ads_address << 7;
	addr = addr | 1;	
	uint8_t b[2] = {addr, SHT20_CMD_SOFTRESET};

	if ((rc = write(fd, b, 2)) != 2) {
		perror("sht20 reset : write  failed");
		return 1;
	}

	usleep(50*1000);

	return 0;
}

int read_temperature(int fd, uint16_t* var) {

	*var = 0;
	uint8_t addr = ads_address << 7;
	addr = addr | 1;	
	uint8_t b[3] = {addr, SHT20_CMD_TEMPERATURE_NO_HOLD, 0};

	if (write(fd, b, 1) != 1) {
		perror("read_temperature : Write register select failed");
		return 1;
	}

	usleep(STH20_TEMPERATURE_WAITINTIME*1000);

	memset(b, 0, 3);
	if(read(fd, b, 3) != 3) {
		perror("read_temperature : Read register failed");
		return 2;
	}

	if(calc_checksum(b, 2) == b[2]) {
		calc_temperature(b, 2, var);
	}
	return 0;
}


int read_humidity(int fd, uint16_t* var) {

	*var = 0;
	uint8_t addr = ads_address << 7;
	addr = addr | 1;	
	uint8_t b[3] = {addr, SHT20_CMD_HUMIDITY_NO_HOLD, 0};

	if (write(fd, b, 1) != 1) {
		perror("read_humidity : Write register select");
		return 1;
	}

	usleep(STH20_HUMIDITY_WAITINTIME*1000);

	*b = 0;
	if(read(fd, b, 3) != 3) {
		perror("read_humidity : Read register failed");
		return 2;
	}

	if(calc_checksum(b, 2) == b[2]) {
		calc_temperature(b, 2, var);
	}
	return 0;
}
int calc_checksum(uint8_t* b, size_t l) {
	int pp = 0x131; // P(x) = x^8+x^5+x^4+1 = 100110001
	int crc = 0;
	for(size_t i=0;i<l;i++) {
		crc ^= *(b+i);
		for (size_t j=8;j>0;j--) {
			if(crc & 0x80) crc = (crc << 1) ^ pp;
			else crc = (crc << 1);
		}
	}
	return crc;
}

int calc_temperature(uint8_t* b, size_t len, uint16_t* result) {
	if(len != 2) {
		perror("fail to calc_temperature");
		return 1;
	}

	uint16_t t = (b[0] << 8) + b[1];
	t &= STH20_STATUS_BIT_MASK;
	t *= 175.72;
	t /= 1 << 16;
	t -= 46.85;
	*result = t;
	return 0;
}

int calc_humidity(uint8_t* b, size_t len, uint16_t* res) {
	if(len != 2) {
		perror("fail to calc_humidity");
		return 1;
	}

	uint16_t t = (b[0]<<8) + b[1];
	t &= STH20_STATUS_BIT_MASK;
	t *= 125.0;
	t /= 1 << 16;
	t -= 6;
	*res = t;
	return 0;
}


