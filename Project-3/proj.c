#include <stdlib.h>
#include <reg932.h>
#include "uart.h"

sbit redB = P2^0;
sbit yellowB = P0^1;
sbit greenB = P2^3;
sbit amberB = P0^2;
sbit blueB = P1^4;
sbit redB2 = P0^0;
sbit yellowB2 = P2^1;
sbit greenB2 = P0^3;
sbit amberB2 = P2^2;
sbit a = P1^0;
sbit b = P1^1;
sbit c = P1^2;
sbit d = P1^3;
sbit e = P1^5;

sbit redL = P2^4;
sbit yellowL = P0^5;
sbit greenL = P2^7;
sbit amberL = P0^6;
sbit blueL = P1^6;
sbit redL2 = P0^4;
sbit yellowL2 = P2^5;
sbit greenL2 = P0^7;
sbit amberL2 = P2^6;

sbit sound = P1^7;

void Sound();
void delay(long k);

void main()
{
	 uart_init();
	 P3M1 = 0x00;
	 P3M2 = 0x00;
	 P2M1 = 0x00;
	 P2M2 = 0x00;
	 P1M1 = 0x00;
	 P1M2 = 0x00;
	 P0M1 = 0x00;
	 P0M2 = 0x01;



	 while(1)
	{
	  	a = 1;
	b = 1;
	delay(50);

	a = 0;
	b = 0;
	c = 1;
	d = 1;
	e = 1;
	delay(20);

	}
/*	while(1){

int k;
for (k=0; k<100; k++)
{Sound();}
delay(10);
for (k=0; k<200; k++)
{Sound();}
delay(10);
for (k=0; k<300; k++)
{Sound();}
delay(30);

			 }
*/	

} 

	 void Sound()
{
	TMOD = 0x01;
	TH0 = 0xF7;
	TL0 = 0xD1;
	//TL0 = 0x6F;

	TR0 = 1;

	while (TF0 != 1);
	sound = ~sound;
	TR0 = 0;
	TF0 = 0;

}

void delay(long x)
{
 long i;
	for(i = 0; i < x*1000; i++);
}