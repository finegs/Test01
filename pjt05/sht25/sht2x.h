#ifndef _SHT2x_H
#define _SHT2x_H

#define   SHT2x_I2C_ADDR 0x40

#define   SHT2x_TEMP     0xF3
#define   SHT2x_HUMID    0xF5

// Get temperature
double getTemperature(int fd);

// Get humidity
double getHumidity(int fd);

#endif
