/**
 * @Author: Wangrenai
 * @Date: 2019-12-31 11:01:52
 * @LastEditors: Wangrenai
 * @LastEditTime: 2019-12-31 16:54:29
 * @Description: file content
 */
/************************************************************************************
Copyright,  LCE STUDIO   
程序名称：延时函数(晶振频率18.432MHz)
功能说明: 延时毫秒与微秒
程序版本：1.0 （2014/06）
阿里旺旺：rob1983
淘宝店铺：http://shop67639654.taobao.com 
************************************************************************************/

#include "iap15w4k58s4.h"	    // 单片机iap15w4k58s4头文件,可以不再加入reg51.h
//#include <intrins.h>			    // 加入此头文件后,可使用_nop_库函数
#include <stdio.h>



void Delay1us()		//@18.432MHz
{
	unsigned char i;

	i = 2;
	while (--i);
}

void Delay1ms()		//@18.432MHz
{
	unsigned char i, j;

	i = 18;
	j = 235;
	do
	{
		while (--j);
	} while (--i);
}

void DelayMS(unsigned int t)
{
	while(t--)
	{
		Delay1ms();
	}
}

void DelayUS(unsigned int t)
{
	while(t--)
	{
		Delay1us();
	}
}



