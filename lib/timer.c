#include "main.h"
#include "timer.h"
#include "port.h"

/* begin of timer 0*/
void timer_0_init(unsigned char mode){
	switch (mode)
	{
		case 0:
		  TMOD = 0x00;
		  break;
		case 1:
		  TMOD = 0x01;
		  break;
		case 2:
		  TMOD = 0x02;
		  break;
		case 3:
		  TMOD = 0x03;
		  break;
	}
}

void timer_0_set_counter_value(unsigned char TH, unsigned char TL){
	TH0 = TH;
	TL0 = TL;
}

void timer_0_start(){
	TR0 = 1;
}

void timer_0_stop(){
	TR0 = 0;
}

void timer_0_clear_flowflag(){
	TF0 = 0;
}

void timer_0_reset(){
	while(!TF0);
	timer_0_stop();
  timer_0_clear_flowflag();
}

void timer_0_interrupt_init(){
	ET0 = 1;
	EA = 1;
}

/*end of timer 0*/