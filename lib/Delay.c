#include"delay.h"
#include"main.h"


void Delay_ms(unsigned int t)
{
	unsigned int x, y;
	for(x = 0; x<t; x++)
	{
		for(y=0; y<113; y++);
	}
}

void Timer0_delay_us(unsigned int t){
	unsigned int load_value;
	load_value = 65536 - t;
	TH0 = load_value >> 8;
	TL0 = load_value & 0x00FF;
	//tai sao khi thay TR0=1 boi timer_0_start() thi lai loi???
	TR0 = 1;
	while(!TF0);
	TR0 = 0;
	TF0 = 0;
}

void Timer0_delay_ms(unsigned int t){
	int i;
	for(i = 0; i<t; i++){
		Timer0_delay_us(1000);
	}
}

	