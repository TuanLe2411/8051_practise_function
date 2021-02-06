#include "main.h"
#include "port.h"
#include "delay.h"
#include "sensor.h"

#define DS18B20_skip_rom 0xCC
#define DS18B20_convert_t 0x44
#define DS18B20_read_scratchpad 0xBE

/*start of Sensor DS18B20 */
unsigned char DS18B20_reset()
{
	unsigned char result;
	
	DS18B20_PIN = 0;
	Timer0_delay_us(480);
	
	DS18B20_PIN = 1;
	Timer0_delay_us(70);
	
	result = DS18B20_PIN;
	
	Timer0_delay_us(410);

	return result;
}

void DS18B20_write_1()
{
	DS18B20_PIN = 0;
	Timer0_delay_us(6);
	
	DS18B20_PIN = 1;
	Timer0_delay_us(64);
}

void DS18B20_write_0()
{
  DS18B20_PIN = 0;
	Timer0_delay_us(60);
	
	DS18B20_PIN = 1;
	Timer0_delay_us(10);
}

void DS18B20_write_bit(unsigned char b)
{
	if(b == 1){
		DS18B20_write_1();
	}
	else{
		DS18B20_write_0();
	}
}

unsigned char DS18B20_read_bit()
{
  unsigned char result;
	
	DS18B20_PIN = 0;
	Timer0_delay_us(6);
	
	DS18B20_PIN = 1;
	Timer0_delay_us(9);
	
	result = DS18B20_PIN;
	Timer0_delay_us(55);

	return result;
}

void DS18B20_write_byte(unsigned char b)
{
	unsigned char i = 8;
	while(i--)
	{
		DS18B20_write_bit(b & 0x01);
		b >>= 1;
	}
}

unsigned char DS18B20_read_byte()
{
	unsigned char i = 8, result = 0;
	
	while(i--)
	{
		result >>= 1;
		result |= (DS18B20_read_bit() << 7);
	}
	
	return result;
}

unsigned int DS18B20_read_data()
{
	unsigned int dt;
	
	while(DS18B20_reset());
	DS18B20_write_byte(DS18B20_skip_rom);
	DS18B20_write_byte(DS18B20_convert_t);
	
	Timer0_delay_ms(750);
	
	while(DS18B20_reset());
	DS18B20_write_byte(DS18B20_skip_rom);
	DS18B20_write_byte(DS18B20_read_scratchpad);
	
	dt = DS18B20_read_byte();
	dt = (DS18B20_read_byte() << 8) | dt;
	return dt;
}

/*end of Sensor DS18B20 */
