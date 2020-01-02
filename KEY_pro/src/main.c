/************************************************************************************
Copyright,  LCE STUDIO   
程序名称：按键检测（晶振频率18.432MHz） 
功能说明: 按键控制LED转换，按键按下后低电平，未按时为高电平；
          按键1后,LED1点亮;按键2后,LED2点亮;按键3后,LED3点亮；按键4后，LED全亮。 

************************************************************************************/

#include "config/iap15w4k58s4.h"	       		 	// 单片机IAP15W4K58S4头文件,可以不再加入reg51.h
#include "driver/delay.h"		            		// 延时函数头文件

__sbit __at(0xA0)  KEY1;								// 定义LED1
__sbit __at(0xA1)  KEY2;								// 定义LED2
__sbit __at(0xA2)  KEY3;
__sbit __at(0xA3)  KEY4;
__sbit __at(0xC8)  LED1;
__sbit __at(0xC9)  LED2;
__sbit __at(0xCA)  LED3;


void main()		                         // 主函数     
{

	P2M0=0X00;
	P2M1=0X00;
	P5M1=0X00;
	P5M1=0X00;
	DelayMS(100);							   
	DelayUS(100);
	LED1 = 1;
	LED2 = 1;
	LED3 = 1;
	KEY1 = 1;
	KEY2 = 1;
	KEY3 = 1;
	KEY4 = 1;	
  DelayMS(100);
  DelayUS(100);
  while (1)		                        // 主循环 
  {
		if (KEY1 == 0)
			{
				LED1 = 0;											// LED1 点亮
				DelayMS(1000);	            	// 延时1秒
				LED1 = 1;											// LED1	熄灭			 
			}
		else if (KEY2 == 0)
		   {
				LED2 = 0;											// LED2 点亮
  	    DelayMS(1000) ;	            	// 延时1秒
				LED2 = 1;											// LED2	熄灭	
			}

		else if (KEY3 == 0)
			{
				LED3 = 0;	            	      // LED3 点亮
    		DelayMS(1000); 	              // 延时1秒
				LED3 = 1;											// LED3	熄灭	
			}
		else if (KEY4 == 0)
			{
				LED1 = 0;	            	     // LED1 点亮
				LED2 = 0;	            	     // LED2 点亮
				LED3 = 0;	            	     // LED3 点亮				
    		DelayMS(1000); 	             // 延时1秒
				LED1 = 1;	            	     // LED1 熄灭
				LED2 = 1;	            	     // LED2 熄灭
				LED3 = 1;	            	     // LED3 熄灭
 
			}
  }
}
