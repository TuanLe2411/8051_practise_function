/*
	Canh bao: CHI DUNG MOT KICH BAN TAI MOT THOI DIEM
*/

#ifndef _CRIPT_H_
#define _CRIPT_H_

void LCD1602_test();
void lamp_sensor_control();
void display_realtime_DS1307_Lcd1602();
void display_realtime_timer0_Lcd1602(unsigned char Hour, unsigned char Minu, unsigned char Sec);
void display_temp_LM35_lcd1602();
void display_temp_DS28B20_lcd1602();
void display_temp_DS28B20_7segs();

void timer_multiFunction_timer0_lcd1602();

#endif