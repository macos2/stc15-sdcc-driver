#include "LM032L.h"

#define RS P20 //RS=0 CODE,RS=1 DDRAM
#define RW P21 //RW=0 WRITE,RW=1 READ
#define E P22 //E=0 disable,E=1 enable
#define DATA P1 //code or data

extern void lm032l_delay(){
char i=0x4F;
	while(i)i--;
}

void lm032l_init(){
	E=0;
	RS=0;
	RW=0;
	DATA=LM032L_DISPLAY_CTRL|0x01<<2|0x00<<1|0x00<<0;
	E=1;
	lm032l_delay();
	E=0;
	DATA=LM032L_FUNC_CTRL|0x01<<4|0x01<<3|0x01<<2;
	E=1;
	lm032l_delay();
	E=0;
	
}

unsigned char lm032l_busy(){
	unsigned char result=0x80;
	E=0;
	RS=0;
	RW=1;
	DATA=0xFF;
	E=1;
	lm032l_delay();
	result=DATA;
	E=0;
	RW=0;
	return result&0x80;
}

unsigned char lm032l_read_data(unsigned char addr){
	unsigned char result=0x00;
	lm032l_write_code(addr|LM032L_DDRAM_ADDR);
	RW=1;
	RS=1;
	DATA=0x00;
	E=1;
	lm032l_delay();
	result=DATA;
	E=0;
	return result;
}

void lm032l_write_data(unsigned char addr,unsigned char D){
	lm032l_write_code(addr|LM032L_DDRAM_ADDR);
	RS=1;
	DATA=D;
	E=1;
	lm032l_delay();
	E=0;
}

void lm032l_write_data_direct(unsigned char D){
	E=0;
	RS=1;
	DATA=D;
	E=1;
	lm032l_delay();
	E=0;
}

void lm032l_write_code(unsigned char D){
	E=0;
	RS=0;
	RW=0;
	DATA=D;
	E=1;
	lm032l_delay();
	E=0;
}

void lm032l_write_string(unsigned char addr,char *d,unsigned char len){
	unsigned char i=0;
	if(len==0)return;
	lm032l_write_data(addr,d[i]);
	while(i<(len-1)){
		i++;
		lm032l_write_data_direct(d[i]);
	}
}
