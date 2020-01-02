# CC 编译工具声明
# # stcgal 烧录工具位置
# # 功能是编译并完成下载
##===================变量定义================
CC = sdcc
DRIVER = driver
BUILD = ../build
CFG = config
BIN = ../bin

##项目名称只允许英文
TARGET = main1

FLASHTOOL =stcgal#烧写工具
BAUD = 115200##波特率
PORT = /dev/ttyUSB0##串口

#获取所有的.h文件
INC = ${wildcard ${DRIVER}/*.h} \
	  ${wildcard ${CFG}/*.h}
	  
	  
#获取所有的.c文件
SRC = ${wildcard ${DRIVER}/*.c} \
	  ${wildcard ${CFG}/*.c} \
	  main.c

#把.c后缀替换为.o,并加上目录
#OBJ = ${patusbst %.c, ${BUILD}/%.o,${notdir ${SRC}}}
	  	  
##==========================================
#
all : $(TARGET).bin

$(TARGET).bin : $(TARGET).hex
	@objcopy -I ihex -O binary ${BIN}/*.hex ${BIN}/$@
	@echo "5-  Main.bin Compile done."

#            
$(TARGET).hex : $(TARGET).ihx
	@packihx ${BUILD}/*.ihx > ${BIN}/$@
	@echo "4-  Main.hex Compile done."

###需要添加新增文件
$(TARGET).ihx : $(TARGET).rel delay.rel
	@$(CC) ${BUILD}/*.rel -o ${BUILD}/$@
	@echo "3-  Main.ihx Compile done."


#
$(TARGET).rel : main.c ${INC} frist
	@$(CC) -c main.c -o ${BUILD}/$@
	@echo "2-  Main.rel Compile done."


delay.rel : ${SRC} frist
	@$(CC) -c ${DRIVER}/delay.c -o ${BUILD}/$@
	@echo "1-  delay Compile done."


##为了便利调试
#delay.rel1 : ${SRC}(添加.c模板)
#	$(CC) -c ${DRIVER}/delay1.c -o ${BUILD}/
#	@echo "delay1 Compile done."




frist:
	if [ ! -d $(BIN) ]; then mkdir -p $(BIN); fi;
	if [ ! -d $(BUILD) ]; then mkdir -p $(BUILD); fi;
	



#===================================
.PHONY:clean flash all frist call
##清理编译文件
clean:
	@rm -rf ${BIN}/*.*
	@rm -rf $(BUILD)/*.lk $(BUILD)/*.bin $(BUILD)/*.asm $(BUILD)/*.lst \
	$(BUILD)/*.mem $(BUILD)/*.rst $(BUILD)/*.lnk $(BUILD)/*.rel \
	$(BUILD)/*.sym $(BUILD)/*.ihx $(BUILD)/*.hex $(BUILD)/*.map
	@echo "A-  Clean BIN  Compile done."

call:
	@rm -rf ${BIN} ${BUILD}
	@echo "KALL-  Clean ALL  Compile done."
##烧录固件
flash:
	$(FLASHTOOL) -p ${PORT} -b $(BAUD) $(BIN)/$(TARGET).bin
	@echo "B-  Flash  Compile done."