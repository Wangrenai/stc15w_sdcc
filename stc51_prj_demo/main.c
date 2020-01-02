/**
 * @Author: Wangrenai
 * @Date: 2019-12-31 11:01:52
 * @LastEditors: Wangrenai
 * @LastEditTime: 2019-12-31 16:35:57
 * @Description: file content
 */
/************************************************************************************
Copyright,  LCE STUDIO  
程序名称：LED点亮试验（晶振频率18.432MHz）  
功能说明: 1. 启动后光耦继电器AQY212EH输出闭合2秒后再断开。
          2. 启动后LED1、LED2和LED3按间隔2秒闪烁。          
程序版本：1.0 （2015/06）
阿里旺旺：rob1983
淘宝店铺：http://shop67639654.taobao.com
************************************************************************************/


#include "iap15w4k58s4.h"	       		 	// 单片机IAP15W4K58S4头文件,可以不再加入reg51.h
#include "delay.h"		            		// 延时函数头文件

__sbit __at(0xC8) LED1;								// 定义LED1
__sbit __at(0xC9) LED2;								// 定义LED2
__sbit __at(0xCA) LED3;								// 定义LED3
__sbit __at(0xB5) PWM_output;						// 定义光耦AQY212EH控制脚

/*void Delay1us() //@18.432MHz
{
	unsigned char i;

	i = 2;
	while (--i)
		;
}

void Delay1ms() //@18.432MHz
{
	unsigned char i, j;

	i = 18;
	j = 235;
	do
	{
		while (--j)
			;
	} while (--i);
}

void DelayMS(int t)
{
	while (t--)
	{
		Delay1ms();
	}
}

void DelayUS(int t)
{
	while (t--)
	{
		Delay1us();
	}
}
*/

void main()		                    		// 主函数     
{
	P3M0=0X00;
	P3M1=0X00;
	P5M0=0X00;
	P5M1=0X00;
	PWM_output = 0;											// 光耦继电器AQY212EH输出闭合
 	DelayMS(2000);		            			// 延时2秒
 	DelayUS(500);		            				// 延时500微秒
	PWM_output = 1;											// 光耦继电器AQY212EH输出断开

	while(1)		                				// 主循环 
  {
		LED1 = 0;	               					// LED1点亮	   
		LED2 = 0;	              					// LED2点亮
		LED3 = 0;	               					// LED1点亮	   
    DelayMS(2000);		        				// 延时2秒
			
		LED1 = 1;	              					// LED1熄灭
		LED2 = 1;	               					// LED2熄灭					
		LED3 = 1;	               					// LED1熄灭   
    DelayMS(2000);							    	// 延时2秒
  }
}

									