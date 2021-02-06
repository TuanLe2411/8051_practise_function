#include "main.h"
#include "port.h"
#include "cript.h"
#include "..\lib\display.h"
#include "..\lib\delay.h"
#include "..\lib\ADC0804.h"
#include "..\lib\timer.h"
#include "..\lib\sensor.h"
#include "..\lib\transport.h"
#include "..\lib\realtime.h"

unsigned char * code Days[] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};

void lamp_sensor_control(){
	unsigned char adc_value;
	lamp_control = 0;
	while(1)
	{		
		while(P0^0== 0){
		adc_value = ADC0804_Read();
		if(adc_value < 20){
			lamp_control = 1;
		}
		if(adc_value > 60) {
			lamp_control = 0;
		}
		if((adc_value >= 20)&&(adc_value <= 60)){
			while(1) {
				unsigned char dt;
				dt = ADC0804_Read();
				if((dt < 20)||(dt > 60)) break;
				lamp_control = 1;
				Delay_ms(500);
				lamp_control = 0;
				Delay_ms(500);
			}
		}
	 }
	}
}

void LCD1602_test(){
	LCD_Init();
	while(1){
		LCD_SendCommand(0x80);
		LCD_Puts("LCD test success");
	}
}

void display_realtime_DS1307_Lcd1602(){
  unsigned char Hour, Minute, Second, Mode;
	unsigned char	Day, Date, Month, Year, old_second;
	
	Soft_I2c_Init();
  LCD_Init();
	Ds1307_Init();
	
	while(1)
	{
		Ds1307_Read_Time(&Hour, &Minute, &Second, &Mode);
		if(old_second != Second)
		{ 
			old_second = Second;
			LCD_SendCommand(0x84);
			LCD_PutChar(Hour/10+0x30);
			LCD_PutChar(Hour%10+0x30);
			LCD_PutChar(':');
			LCD_PutChar(Minute/10+0x30);
			LCD_PutChar(Minute%10+0x30);
			LCD_PutChar(':');
			LCD_PutChar(Second/10+0x30);
			LCD_PutChar(Second%10+0x30);

			Ds1307_Read_Date(&Day, &Date, &Month, &Year);
			LCD_SendCommand(0xC1);
			LCD_Puts(Days[Day-1]);
			LCD_PutChar(' ');
			LCD_PutChar(Date/10+0x30);
			LCD_PutChar(Date%10+0x30);
			LCD_PutChar('/');
			LCD_PutChar(Month/10+0x30);
			LCD_PutChar(Month%10+0x30);
			LCD_Puts("/20");
			LCD_PutChar(Year/10+0x30);
			LCD_PutChar(Year%10+0x30);
		}
	}
}

void display_temp_DS28B20_lcd1602(){
	unsigned int temp;
	LCD_Init();
  timer_0_init(1);
	while(1)
	{
		LCD_Clear();
		LCD_SendCommand(0x80);
		LCD_Puts("Temp:");
		temp = DS18B20_read_data();
		temp = (int)(temp*100/16.0);
		LCD_Display_Number(temp/100);
		LCD_PutChar('.');
		LCD_Display_Number(temp%100);
		LCD_Puts("oC");
		Timer0_delay_ms(60000);
	}
}

void timer_multiFunction_timer0_lcd1602(){
}
