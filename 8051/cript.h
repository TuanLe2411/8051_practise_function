/*
	Canh bao: CHI DUNG MOT KICH BAN TAI MOT THOI DIEM
*/

#ifndef _CRIPT_H_
#define _CRIPT_H_

// testing lcd display
void LCD1602_test();

// lamp control by temp sensor
void lamp_sensor_control();

// get real time by DS1307 and display in lcd
void display_realtime_DS1307_Lcd1602();

//create realtime just by 8051 ,lcd and keyboard
void display_realtime_timer0_Lcd1602(unsigned char Hour, unsigned char Minu, unsigned char Sec);

//
void display_temp_LM35_lcd1602();

//
void display_temp_DS28B20_lcd1602();

//
void display_temp_DS28B20_7segs();

//create multi feature clock( realtime, timer, countdown...) just using 8051, lcd and keyboard
void timer_multiFunction_timer0_lcd1602();

#endif
