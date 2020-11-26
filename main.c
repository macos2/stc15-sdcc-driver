#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "main.h"

__xdata char string[256];
unsigned char ex_t3 = 0;
unsigned char writed;
unsigned display_changed;
char temp;

void usart3_interrupt() __interrupt 17 {
	temp = 0x00;
	if (S3CON & 0x01) //receive interrupt
			{
		temp = S3BUF;
		switch (temp) {
		case '\r':
			if(strcmp(string,"pic")==0)
				display_changed |=0x02;
			writed = 0;
			string[0] = '\0';
			display_changed |= 0x01;
			break;
		case '\b':
			if (writed > 0) {
				string[writed] = '\0';
				writed--;
				display_changed |= 0x01;
			}
			break;
		default:
			if (writed < 256) {
				string[writed] = temp;
				string[writed + 1] = '\0';
				writed++;
				display_changed |= 0x01;
			}
			break;
		}
		S3CON &= ~0x01;
	}
	if (S3CON & 0x02) //transfer interrupt
	{
		S3CON &= ~0x02;
	}
	if(temp!=0x00){
		S3BUF = temp;
	}
}

void timer3_interrupt() __interrupt 19 {
	unsigned char *i;
	ex_t3++;
	if (ex_t3 > 20) {
		if (display_changed == 0x00)
			return;
		ex_t3 = 0;
		lm032l_write_string(0x00, "                    ", 20);
		if (writed <= 20) {
			lm032l_write_string(0x00, string, writed);
		} else {
			i = string + writed - 20;
			lm032l_write_string(0x00, i, 20);
		}
		lm032l_write_string(0x40, "Hello!!", 7);
		lm032l_write_data_direct(0x00);
		if(display_changed&0x02)sed1565_write_picture(0,13,102,64,pic);
		display_changed = 0x00;
	}
/*
	for(i=0;i<4;i++){
		sed1565_write_16x16_Font(10,c,taobaobao+t);
		t+=32;
		c+=16;
	}
//	for(i=0;i<3;i++){
//		sed1565_write_8x16_Font(2,c,taobaobao+t);
//		t+=16;
//		c+=8;
//	}
	for(i=0;i<2;i++){
		sed1565_write_16x16_Font(18,c,taobaobao+t);
		t+=32;
		c+=16;
	}*/
}

void timer3_init() {
	T4T3M |= 0x02;
	T3L = 0xB0;
	T3H = 0x3C; //65535-50000us+1=0x3cB0 ~50ms
	T4T3M |= 0x08; //T3 start
	IE2 |= 0x01 << 5; //T3 interrupt enable
	EA = 1;
}

void usart3_init() {
	//115200bps@11.0592MHz
	S3CON = 0x10;
	S3CON &= 0xBF;
	AUXR |= 0x04; //1T
	T2L = 0xE8;
	T2H = 0xFF;
	AUXR |= 0x10;
	IE2 |= 0x01 << 3;
}

void main() {
	unsigned char i;
	timer3_init();
	usart3_init();
	lm032l_init();
	sed1565_init();
	string[0] = '\0';
	writed = 0;
	display_changed = 0x01;
	lm032l_write_code(LM032L_CHAR_ADDR);
	for(i=0;i<8;i++){
		lm032l_write_data_direct(cgram_tab[i]);
	}
	while (1);
}
