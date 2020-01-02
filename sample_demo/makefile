all:
	    sdcc main.c
	    packihx main.ihx > main.hex
		makebin -p main.ihx main.bin
			
clean:
	    rm -rf *.asm *.lst *.mem *.rst *.lnk *.rel *.sym *.ihx *.hex *.map *.lk *.bin

flash:
	    stcgal -b 1200 -l 1200 main.bin 
