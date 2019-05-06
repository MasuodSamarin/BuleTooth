#ifndef __LCD_DRV_API_H__
#define __LCD_DRV_API_H__

#include "sdk_cfg.h"

///************************************************************/
///****************������Ļ�Ĵ�С
///****************˵������������һ�����Ӧһ��bit
///************************************************************/

/*****************************************************************
66�� AC69 ϵ�� SPI �ӿ��ж��顣 �ֱ����¡�
SPI0 ���鱻�ڲ��� FLASH �õ��ˣ� ���Խ����� SPI1 SPI2 ���Ӧ�� IO �ڡ�


SPI0
PD0 SPI0CLKA PD1 SPI0DOA PD2 SPI0DIA PD3 SPI0CSA    ---  ��Ӧ����A����
PB8 SPI0CLKB PB7 SPI0DOB PB5 SPI0DIB PB6 SPI0CSB    ---  ��Ӧ����B����


SPI2
PB0 SPI2CLKA PB1 SPI2DOA PB2 SPI2DIA       ---  ��Ӧ����A����
PC0 SPI2CLKB PC1 SPI2DOB PC2 SPI2DIB       ---  ��Ӧ����B����


SPI1
PB11 SPI0CLKB PB12 SPI0DOB PB10 SPI0DIB    ---  ��Ӧ����A����
PC4  SPI0CLKB PC5  SPI0DOB  PC3 SPI0DIB    ---  ��Ӧ����B����

LCD-CS   --- PB9
LCD-RES  --- PB8
LCD-AO   --- PB7
LCD-CLK  --- PB11
LCD-DAT  --- PB12

*****************************************************************/

#define  LCDPAGE            8
#define  LCDCOLUMN          128

#define SCR_WIDTH           LCDCOLUMN
#define SCR_HEIGHT          (LCDPAGE*8)



//SPI1�ӿ�ѡ��
#if 1//
//SPI1A
#define LCD_SPI_SET_GROUP()       do{JL_IOMAP->CON1 &= ~BIT(4);}while(0)
#define LCD_SPI_SET_DATAIN()      do{JL_PORTB->DIR &= ~BIT(10);}while(0)
#define LCD_SPI_SET_CLK()	      do{JL_PORTB->DIR &= ~BIT(11);}while(0)//��4��
#define LCD_SPI_SET_DATAOUT()     do{JL_PORTB->DIR &= ~BIT(12);}while(0)//��5�ţ�6��3v3

#else
//SPI1B
#define LCD_SPI_SET_GROUP()       do{JL_IOMAP->CON1  |= BIT(4);}while(0)
#define LCD_SPI_SET_DATAIN()      do{PORTC_DIR &= ~BIT(2);}while(0)
#define LCD_SPI_SET_CLK()	      do{PORTC_DIR &= ~BIT(5);}while(0)
#define LCD_SPI_SET_DATAOUT()     do{PORTC_DIR &= ~BIT(8);}while(0)

#endif

#define LCD_DATA_OUT()
#define	LCD_CLK_OUT()
#define LCD_SPI_SET_MODE_OUT()       do{JL_SPI1->CON &= ~BIT(3);}while(0)
#define LCD_SPI_SET_MODE_INOUT()     do{JL_SPI1->CON |= BIT(3);}while(0)


#define	LCD_A0_OUT()	    do{JL_PORTB->DIR &= ~BIT(10);}while(0)//������
#define	LCD_A0_L()	        do{JL_PORTB->OUT &= ~BIT(10);}while(0)
#define	LCD_A0_H()	        do{JL_PORTB->OUT |= BIT(10);}while(0)

#define LCD_RES_OUT()	    do{JL_PORTB->DIR &= ~BIT(8);}while(0)//�ڶ���
#define LCD_RES_L()	        do{JL_PORTB->OUT &= ~BIT(8);}while(0)
#define LCD_RES_H()	        do{JL_PORTB->OUT |= BIT(8);}while(0)

#define LCD_CS_OUT()	    do{JL_PORTB->DIR &= ~BIT(9);}while(0)//��һ��
#define LCD_CS_L()	        do{JL_PORTB->OUT &= ~BIT(9);}while(0)
#define LCD_CS_H()	        do{JL_PORTB->OUT |= BIT(9);}while(0)


#define LCD_BL_ON()         //do{PORTB_DIR &= ~BIT(2); PORTB_OUT |= BIT(2);}while(0)
#define LCD_PORT_OUT()      do{LCD_DATA_OUT();LCD_CLK_OUT();LCD_A0_OUT();LCD_RES_OUT();LCD_CS_OUT();}while(0)
#define LCD_PORT_OUT_H()    do{LCD_DATA_OUT();LCD_CLK_OUT();LCD_A0_H();  LCD_RES_H();	LCD_CS_H();}while(0)

//ȫ�ֱ�������
extern u8 disp_buf[];

//��������
void draw_lcd_buf(void);
void lcd_clear(void);
void lcd_init(void);
void lcd_hardware_init(void);
void lcd_128x64_set(u8 page,u8 column);
extern bool font_init(u8 language);
#endif/*__LCD_DRV_API_H__*/
