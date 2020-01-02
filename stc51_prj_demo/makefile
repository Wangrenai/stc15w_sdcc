# CC 编译工具声明
# # stc 烧录工具位置
# # 功能是编译并完成下载
CC    =sdcc
#
main.bin : main.hex
	objcopy -I ihex -O binary main.hex main.bin
#            
main.hex : main.ihx
	packihx main.ihx > main.hex
#
main.ihx : main.rel delay.rel
	$(CC) main.rel delay.rel
#
main.rel : main.c delay.h
	$(CC) -c main.c
#                            
delay.rel : delay.c
	$(CC) -c delay.c
#
clean:
	rm -rf *.lk *.bin *.asm *.lst *.mem *.rst *.lnk *.rel *.sym *.ihx *.hex *.map
