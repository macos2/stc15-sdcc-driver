#include "stc15.h"

#ifndef SED1565_H_
#define SED1565_H_

static unsigned char sed1565_display_on=0b10101111;
static unsigned char sed1565_display_off=0b10101110;

static unsigned char sed1565_start_line_set=0b01000000;//0b01xxxxxx:xxxxxx line address from 0 to 63 line
static unsigned char sed1565_page_address_set=0b10110000;//0b1011xxxx:xxxx page address from 0 to 8
//column address from 0 to 131
static unsigned char sed1565_column_address_set_hight_bit=0b00010000;//0b0001xxxx:xxxx column hight 4bit
static unsigned char sed1565_column_address_set_low_bit=0b00000000;//0b0000xxxx:xxxx column low 4bit

// sed1565_read_modify_write_start and sed1565_read_modify_write_end is pair for using
static unsigned char sed1565_read_modify_write_start=0b11100000;//save the current column address which the mcu begin the read|modify|write opertions.
//do some read|modify|write opertions betweed start and end;
static unsigned char sed1565_read_modify_write_end=0b11101110;//return to column address which the mcu begin the read|modify|write opertions.

static unsigned char sed1565_lcd_bias=0b10100010;//0b1010001x:x=0 1/9bias,x=1 1/7 bias.

static unsigned char sed1565_display_all_point_off=0b10100100;//not display all point display.
static unsigned char sed1565_display_all_point_on=0b10100101;// display all point display.
static unsigned char sed1565_reset=0b11100010;
static unsigned char sed1565_adc_select= 0b10100000;// 0b1010000x:x=0 normal,x=1 reverse
static unsigned char sed1565_common_output_mode_select=0b11000000;//0b1100x000:x=0 normal,x=1 reverse direction


void sed1565_init();
/*
 * return the 8bit state info like this formal "BUSY ADC ON/OFF RESET 0 0 0 0";
*/
unsigned char sed1565_state();
void sed1565_read_data(unsigned char col_addr,unsigned char *result,unsigned char count);
void sed1565_write_data(unsigned char iscode,unsigned char *D,unsigned char count);
void sed1565_set_coluumn(unsigned char col);
void sed1565_set_line(unsigned char line);
void sed1565_set_page(unsigned char page);
void sed1565_write_16x16_Font(unsigned char page,unsigned char col,unsigned char *f);
void sed1565_write_8x16_Font(unsigned char page,unsigned char col,unsigned char *f);
void sed1565_write_picture(unsigned char page,unsigned char col,unsigned char w,unsigned char h,unsigned *i);
#endif
