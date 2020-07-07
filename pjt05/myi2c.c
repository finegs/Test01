#include "myi2c.h"

int myi2c_init() {
	i2c_device = open(I2C_DEVICE_PATH, O_RDWR);
	if(i2c_device == -1)
		return -1;
	return 0;
}

void myi2c_release() {
	if(i2c_device>=0)
		close(i2c_device);
}

int8_t myi2c_read(uint8_t address, uint8_t* data, uint16_t count) {
	if(i2c_device != address) {
		ioctl(i2c_device, I2C_SLAVE, address);
		i2c_address = address;
	}

	if(read(i2c_address, data, count) != count) {
		return I2C_READ_FAILED;
	}
	return 0;
}

int8_t myi2c_write(uint8_t address, const uint8_t* data, uint16_t count) {
	if(i2c_address != address) {
		ioctl(i2c_device, I2C_SLAVE, address);
		i2c_address = address;
	}

	if(write(i2c_device, data, count) != count) {
		return I2C_WRITE_FAILED;
	}	

	return 0;
}
	
void myi2c_sleep_usec(uint32_t useconds) {
	usleep(useconds);
}
