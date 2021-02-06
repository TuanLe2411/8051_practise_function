#ifndef _SENSOR_H_
#define _SENSOR_H_

/*start of Sensor DS18B20*/
unsigned char DS18B20_reset();
void DS18B20_write_1();
void DS18B20_write_0();
void DS18B20_write_bit(unsigned char b);
unsigned char DS18B20_read_bit();

void DS18B20_write_byte(unsigned char b);
unsigned char DS18B20_read_byte();
unsigned int DS18B20_read_data();

/*end of Sensor DS18B20*/


#endif
