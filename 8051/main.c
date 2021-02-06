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


void main()
{
	//timer_multiFunction_timer0_lcd1602();
	lamp_sensor_control();
}

void Timer_0_interrupt() interrupt 1
{
}


