/*
 * main.h
 *
 *  Created on: 2020年11月23日
 *      Author: tom
 */

#ifndef MAIN_H_
#define MAIN_H_
#include "stc15.h"
#include "LM032L.h"
#include "lcd12864-sed1565.h"

__code unsigned char cgram_tab[]={
		0b00100,
		0b01110,
		0b10101,
		0b10101,
		0b10101,
		0b00100,
		0b01010,
		0b10001,
		//
		0b00100,
		0b01110,
		0b10101,
		0b10101,
		0b10101,
		0b00100,
		0b01010,
		0b10001,
		//
		0b00100,
		0b01110,
		0b10101,
		0b10101,
		0b10101,
		0b00100,
		0b01010,
		0b10001,
};

__code unsigned char taobaobao[]={
		0x40,0x40,0x42,0xCC,0x00,0x08,0x28,0x48,
		0x89,0x0E,0xC8,0x38,0x08,0x08,0x00,0x00,
		0x00,0x40,0x20,0x1F,0x20,0x50,0x48,0x44,
		0x42,0x41,0x42,0x44,0x58,0x40,0x40,0x00,/*"这",0*/
		0x00,0x00,0x00,0x7F,0x49,0x49,0x49,0x49,
		0x49,0x49,0x49,0x7F,0x00,0x00,0x00,0x00,
		0x81,0x41,0x21,0x1D,0x21,0x41,0x81,0xFF,
		0x89,0x89,0x89,0x89,0x89,0x81,0x81,0x00,/*"是",1*/
		0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
		0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"一",2*/
		0x80,0x80,0x40,0x20,0x10,0x08,0x04,0xC3,
		0x04,0x08,0x10,0x20,0x40,0x80,0x80,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"个",3*/
		0x08,0xF8,0x08,0x00,0x00,0x00,0x00,0x00,
		0x20,0x3F,0x20,0x20,0x20,0x20,0x30,0x00,/*"L",4*/
		0xC0,0x30,0x08,0x08,0x08,0x08,0x38,0x00,
		0x07,0x18,0x20,0x20,0x20,0x10,0x08,0x00,/*"C",5*/
		0x08,0xF8,0x08,0x08,0x08,0x10,0xE0,0x00,
		0x20,0x3F,0x20,0x20,0x20,0x10,0x0F,0x00,/*"D",6*/
		0x10,0x60,0x02,0x8C,0x00,0xFE,0x02,0xF2,
		0x02,0xFE,0x00,0xF8,0x00,0xFF,0x00,0x00,
		0x04,0x04,0x7E,0x01,0x80,0x47,0x30,0x0F,
		0x10,0x27,0x00,0x47,0x80,0x7F,0x00,0x00,/*"测",7*/
		0x40,0x40,0x42,0xCC,0x00,0x90,0x90,0x90,
		0x90,0x90,0xFF,0x10,0x11,0x16,0x10,0x00,
		0x00,0x00,0x00,0x3F,0x10,0x28,0x60,0x3F,
		0x10,0x10,0x01,0x0E,0x30,0x40,0xF0,0x00,/*"试",8*/
};

__code unsigned char pic[]={
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x80,0x80,0x80,0x00,0x00,0x80,0x80,
		0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x20,0x20,0xA0,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,
		0xF0,0xF8,0x38,0x38,0x38,0x10,0x10,0x08,
		0x08,0x04,0x00,0x02,0x01,0x01,0x00,0x02,
		0x02,0x0E,0x0B,0x07,0x06,0x06,0x02,0x02,
		0x02,0x00,0x04,0x04,0x04,0x00,0x08,0x08,
		0x18,0x38,0x18,0xB8,0xF8,0xF0,0xE0,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0xC0,0x10,0x87,0xE3,0xF1,
		0xF8,0xFC,0xFC,0xFC,0xFC,0xFE,0xFE,0xFC,
		0xFC,0xF8,0xF8,0xF0,0xE0,0x80,0x00,0x00,
		0x00,0x00,0x00,0xC0,0xF0,0xF8,0xF8,0xFC,
		0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFC,0xFC,
		0xF8,0xF9,0xE3,0x8F,0x30,0x80,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0xFF,0x00,0x00,0x3F,0xFF,0xFF,0xFF,0xFF,
		0xFF,0xFF,0xF9,0xF7,0xF9,0xFF,0xFF,0xFF,
		0xFF,0xFF,0xFF,0x3F,0x00,0x00,0x80,0x00,
		0x00,0x3F,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,
		0xF9,0xFE,0xFB,0xFF,0xFF,0xFF,0xFF,0xFF,
		0x7F,0x1F,0x00,0x00,0x1C,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,
		0x7C,0xF8,0xF0,0xE1,0xC3,0xC3,0xC7,0x87,
		0x07,0x07,0x07,0x07,0x07,0x03,0x03,0x01,
		0x00,0x00,0x00,0x01,0x07,0x01,0x00,0x00,
		0x00,0x00,0x01,0x03,0x03,0x03,0x07,0x07,
		0x87,0x83,0x83,0x03,0x41,0x00,0x20,0x10,
		0x00,0x04,0x01,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x01,0x03,0x07,0x2F,0x03,0x00,0x00,0x00,
		0x00,0x00,0x10,0x08,0x00,0x00,0x00,0x00,
		0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,
		0x05,0x00,0x00,0x20,0x00,0x00,0x01,0x0F,
		0xFF,0xFE,0xF8,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,0x80,
		0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x40,
		0xA0,0xD0,0xE2,0xF0,0xF8,0x3C,0x07,0x03,
		0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x07,0x0F,0x0F,0x0F,0x0F,0x0F,0x0C,0x01,
		0x01,0x01,0x03,0x02,0x02,0x02,0x02,0x02,
		0x02,0x03,0x01,0x00,0x0F,0x1F,0x1F,0x1F,
		0x0F,0x07,0x01,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"C:\Users\tom\Desktop\12864.bmp",0*/
};

#endif /* MAIN_H_ */