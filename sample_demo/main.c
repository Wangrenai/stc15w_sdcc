/*************************************************************************
    > File Name: main.c
    > Author: Wangrenai
    > Mail: wangrenai@hotmail.com 
    > Created Time: Mon Dec 30 00:41:39 2019
 ************************************************************************/

#include <8051.h>


void Delayms(unsigned int ms);

void main()
{
    while(1)
	    {
	        P0=0xfe;
	        Delayms(500);
	        P0=0x01;
	        Delayms(500);
	    }
}

void Delayms(unsigned int ms)
{
    unsigned int i, j;
    for(i = ms; i > 0; i--)
       for(j = 110; j > 0; j--);
    return;

}
