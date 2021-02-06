#include"main.h"
#include"port.h"
#include"display.h"
#include"delay.h"
#include"String.h"

/*start of Lcd Function*/
void LCD_Enable()
{
	LCD_EN = 1;
	Delay_ms(1);
	LCD_EN = 0;  
	Delay_ms(1); 
}

void LCD_Send4Bit(unsigned char Data)
{
	LCD_D4 =  Data&0x01;
	LCD_D5 = (Data>>1)&0x01;
	LCD_D6 = (Data>>2)&0x01;
	LCD_D7 = (Data>>3)&0x01; 
}

void LCD_SendCommand(unsigned char command)
{
  LCD_Send4Bit(command >>4);/* Gui 4 bit cao */
  LCD_Enable();
  LCD_Send4Bit(command);  /* Gui 4 bit thap*/
  LCD_Enable();
}
/* USER CODE END 0 */
void LCD_Clear()
{
  LCD_SendCommand(0x01);  
  Delay_ms(1); 
}

void LCD_Init()
{
  LCD_Send4Bit(0x00);
  LCD_RS = 0;
  LCD_Send4Bit(0x03);
  LCD_Enable();
  LCD_Enable();
  LCD_Enable();
  LCD_Send4Bit(0x02);
  LCD_Enable();
  LCD_SendCommand(0x28); // giao thuc 4 bit, hien thi 2 hang, ki tu 5x8
  LCD_SendCommand(0x0C); // cho phep hien thi man hinh
  LCD_SendCommand(0x06); // tang ID, khong dich khung hinh
  LCD_SendCommand(0x01); // xoa toan bo khung hinh
}

void LCD_Gotoxy(unsigned char x, unsigned char y)
{
  unsigned char address;
    if(!y)address=(0x80+x);
    else address=(0xC0+x);
    LCD_SendCommand(address);

}

void LCD_PutChar(unsigned char Data)
{
  LCD_RS = 1;
  LCD_SendCommand(Data);
  LCD_RS = 0;
}

void LCD_Puts(char *s)
{
    while (*s){
        LCD_PutChar(*s);
      s++;
    }
}

void LCD_Display_Number(unsigned int num){
	unsigned char arr[4];
	unsigned char count = 0;
	unsigned char i;
	while((num / 10) > 0){
		arr[count] = num%10;
		num = num/10;
		count++;
	}
	arr[count] = num;
	for(i = count; i > 0; i--){
		LCD_PutChar(arr[i] + 0x30);
	}
	LCD_PutChar(arr[0] + 0x30);
}
/*end of Lcd Function*/

