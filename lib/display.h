#ifndef _LCD4BIT_H_
#define _LCD4BIT_H_

/* Start of LCD 1602 */
void LCD_Enable();
void LCD_Send4Bit(unsigned char Data);
	
void LCD_Init();
void LCD_Clear();
void LCD_SendCommand(unsigned char command);
void LCD_Gotoxy(unsigned char x, unsigned char y);
void LCD_PutChar(unsigned char Data);

void LCD_Puts(char *s);
void LCD_Display_Number(unsigned int num);
/* End of LCD 1602 */

#endif
