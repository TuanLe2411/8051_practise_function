#ifndef _PORT_H_
#define _PORT_H_

// Khai bao ket noi voi LCD
sbit LCD_RS	= P0^0;
sbit LCD_EN	= P0^1;
sbit LCD_D4	= P0^4;
sbit LCD_D5 = P0^5;
sbit LCD_D6 = P0^6;
sbit LCD_D7 = P0^7;

// Khai bao ket noi voi ADC0804
#define ADC0804_DATA	P2
sbit ADC0804_CS = P1^0;
sbit ADC0804_RD = P1^1;
sbit ADC0804_WR = P1^2;
sbit ADC0804_INTR = P1^3;

// Khai bao ket noi voi DS18B20
sbit DS18B20_PIN = P1^4;

// khai bao ket noi I2C
sbit SOFT_I2C_SCL = P1^6;
sbit SOFT_I2C_SDA = P1^7;

// khai bao cac chan chuc nang
sbit lamp_control = P0^2;

#endif