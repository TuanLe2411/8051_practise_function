
#ifndef _TIMER_H_
#define _TIMER_H_

/*start of time_0_funtion*/

void timer_0_init(unsigned char mode);
void timer_0_set_counter_value(unsigned char TH, unsigned char TL);
void timer_0_interrupt_init();
void timer_0_start();
void timer_0_stop();
void timer_0_reset();
void timer_0_clear_flowflag();

/*end of time_0_funtion*/

#endif
