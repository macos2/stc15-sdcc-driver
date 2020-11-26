#include "lcd12864-sed1565.h"

#define A0 P23 //A0=0 CODE,A0=1 DDRAM
#define WR P24 //WR=0 WRITE,WR=1 READ
#define E P25 //E=0 disable,E=1 enable
#define DATA P3 //code or data

extern void sed1565_delay() {
	char i = 0x2f;
	while (i)
		i--;
}

void sed1565_init() {
	unsigned char d = sed1565_adc_select + 1;
	sed1565_write_data(1, &sed1565_reset, 1);
	sed1565_write_data(1, &d, 1);
}

unsigned char sed1565_state() {
	unsigned char result = 0x00;
	DATA = 0xff;
	A0 = 0;
	E = 0;
	WR = 1;
	sed1565_delay();
	E = 1;
	result = DATA;
	E = 1;
	return result;
}

void sed1565_read_data(unsigned char col_addr, unsigned char *result,
		unsigned char count) {
	unsigned char i;
	A0 = 1; //ddram
	WR = 0; //write
	E = 0;
	DATA = col_addr;
	E = 1;
	sed1565_delay();
	E = 0;
	WR = 1; //read
	DATA = 0xFF;
	E = 1;
	sed1565_delay();
	//Dummy Read
	E = 0;
	sed1565_delay();
	for (i = 0; i < count; i++) {
		E = 1;
		sed1565_delay();
		result[i] = DATA;
		i++;
		E = 0;
	}
	return;
}

void sed1565_write_data(unsigned char iscode, unsigned char *D,
		unsigned char count) {
	unsigned char i;
	A0 = iscode ? 0 : 1;
	WR = 0;
	E = 0;
	for (i = 0; i < count; i++) {
		DATA = D[i];
		E = 1;
		sed1565_delay();
		E = 0;
	}

}

void sed1565_set_coluumn(unsigned char col) {
	unsigned char d[] = { sed1565_column_address_set_hight_bit | (col >> 4),
			sed1565_column_address_set_low_bit | (col & 0x0F), };
	sed1565_write_data(1, d, 2);
}

void sed1565_set_line(unsigned char line) {
	unsigned char d = sed1565_start_line_set | (line & 0b00111111);
	sed1565_write_data(1, &d, 1);
}

void sed1565_set_page(unsigned char page) {
	unsigned char d = sed1565_page_address_set | (page & 0x0f);
	sed1565_write_data(1, &d, 1);
}

void sed1565_write_16x16_Font(unsigned char page, unsigned char col,
		unsigned char *f) {
	sed1565_set_line(page);
	//sed1565_set_page(page);
	sed1565_set_coluumn(col);
	sed1565_write_data(0, f, 16);
	sed1565_set_line(page+16);
	//sed1565_set_page(page + 1);
	sed1565_set_coluumn(col);
	sed1565_write_data(0, f + 16, 16);
}
void sed1565_write_8x16_Font(unsigned char page, unsigned char col,
		unsigned char *f) {
	sed1565_set_page(page);
	sed1565_set_coluumn(col);
	sed1565_write_data(0, f, 8);
	sed1565_set_page(page + 1);
	sed1565_set_coluumn(col);
	sed1565_write_data(0, f + 8, 8);
}

void sed1565_write_picture(unsigned char page,unsigned char col,unsigned char w_pix,unsigned char h_pix,unsigned *img){
	unsigned char *i=img;
	unsigned char h;
	h_pix=h_pix/8;
	for(h=0;h<h_pix;h++){
		sed1565_set_page(page+h);
		sed1565_set_coluumn(col);
		sed1565_write_data(0,i,w_pix);
		i+=w_pix;
	}
}
