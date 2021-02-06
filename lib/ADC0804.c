#include "main.h"
#include "ADC0804.h"
#include "port.h"

unsigned char ADC0804_Read()
{
	unsigned char kq;

	// Chon chip
 	ADC0804_CS = 0;

	// Tao xung bat dau chuyen doi
	ADC0804_WR = 1;
	ADC0804_WR = 0;
	ADC0804_WR = 1;

	// Doi cho den khi chuyen doi xong
	while(ADC0804_INTR);

	// Doc gia tri sau khi chuyen doi
	ADC0804_CS = 0;
	ADC0804_RD = 0;
	kq = ADC0804_DATA;
	ADC0804_RD = 1;
 	ADC0804_CS = 1;

	return kq;
}
