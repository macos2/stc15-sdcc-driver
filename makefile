all:main.hex

clean:
	@-rm *.lst *.sym *.rst *.map *.mem *.lk *.rel *.ihx *.hex

main.hex:main.c main.h LM032L.rel lcd12864-sed1565.rel
	sdcc -mmcs51 --less-pedantic  main.c LM032L.rel lcd12864-sed1565.rel -o main.ihx
	packihx main.ihx >$@
	
%.rel:%.c %.h
	sdcc -c -mmcs51 --less-pedantic $< -o $@