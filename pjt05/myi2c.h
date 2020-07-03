#ifndef __MYI2C_H__
#define __MYI2C_H__

#include <stdio.h>
#include <sys/types.h> // open
#include <sys/stat.h>  // open
#include <fcntl.h>     // open
#include <unistd.h>    // read/write usleep
#include <stdlib.h>    // exit
#include <inttypes.h>  // uint8_t, etc
#include <sys/ioctl.h> // ioctl
#include <linux/i2c-dev.h> // I2C bus definitions

#define I2C_DEVICE_PATH "/dev/i2c-%d"

#define I2C_WRITE_FAILED -1
#define I2C_READ_FAILED -1

static int i2c_device = -1;
static uint8_t i2c_address = 0;

int myi2c_init();
void myi2c_release();
int8_t myi2c_read(uint8_t address, uint8_t* data, uint16_t count);
int8_t myi2c_write(uint8_t address, const uint8_t* data, uint16_t count);
void myi2c_sleep_usec(uint32_t useconds);

#endif
