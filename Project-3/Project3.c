
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
unsigned char selector;
void playsound(char x, int c);
int c,i,z,k,ok,repeat;
ok=0;
char song[18] = {'E','E','E','E','E','E','E','G','C','D','E','F','F','F','F','F','E','E'};
int sing[18]={200,200,400,200,200,400,200,200,200,100,800,200,200,300,100,200,200,200};
char song2[21]={'G','A','G','E','G','A','G','E','D','D','B','C','C','G','A','C','B','A','G','A'};
int sing2[21]={300,100,200,400,300,100,200,400,400,200,400,400,200,400,400,200,300,100,200,300,100};
char jb[12]={'J','i','n','g','l','e',' ','B','e','l','l','s'};
int cjb=0;
char sn[12]={'S','i','l','e','n','t',' ','N','i','g','h','t'};
int csn=0;
void tune1();
void sounddelay();
void menu();
void tune2();
void oneOn();
void twoOn();
void keyboard();
void Slights(int x);
void cleareverything();
void delay();
void snake();
void cop();
void Lights(char x);
void timerrupt() interrupt 3
{
  TF1=0;
  TR1=0;
  if (redB2==0)
  {
    redL2=0;
	sounddelay();
	sounddelay();
	sounddelay();
	redL2=1;
	ok=1;
  }
  TH1=0x00;
  TL1=0x00;
  TR1=1;
}
void main()
{
     P3M1 = 0x00;
	 P3M2 = 0x00;
	 P2M1 = 0x00;
	 P2M2 = 0x00;
	 P1M1 = 0x00;
	 P1M2 = 0x00;
	 P0M1 = 0x00;
 P0M2 = 0x00;
 cleareverything();
 uart_init();
 TMOD=0x11;
   TH1=0x00;
   TL1=0x00;
   IT1=1;
   EA=1;
   ET1=1;
   TR1=1;
 ok=0;
 menu();


}
void tune1()
{	
 oneOn();
  	 ES=1;
	 for(cjb=0;cjb<12;cjb++)
	 {
	 uart_transmit(jb[cjb]);
   	 }
   	for (z=0; z<18;z++)
	{
	  Slights((z%11));
	  playsound(song[z],sing[z]);
	  sounddelay();
	  if(ok==1)
	  {
	   z=18;
	   }
	}	  
 }
void playsound(char x,int c)
{
  switch(x){
  case 'A':
  for (i=0;i<c;i++)
  {
	TH0 = 0xEF;
	TL0 = 0x9E;
	TR0 = 1;
	while (TF0 != 1);
	sound = ~sound;
	TR0 = 0;
	TF0 = 0;
  }
  break;
  case 'G':
    for (i=0;i<c;i++)
  {
	TH0 = 0xED;
	TL0 = 0x9C;
	TR0 = 1;
	while (TF0 != 1);
	sound = ~sound;
	TR0 = 0;
	TF0 = 0;
  }
  break;
  case 'F':
    for (i=0;i<c;i++)
  {
	TH0 = 0xEB;
	TL0 = 0x5B;
	TR0 = 1;
	while (TF0 != 1);
	sound = ~sound;
	TR0 = 0;
	TF0 = 0;
  }
  break;
  case 'E':
    for (i=0;i<c;i++)
  {
	TH0 = 0xEA;
	TL0 = 0x22;
	TR0 = 1;
	while (TF0 != 1);
	sound = ~sound;
	TR0 = 0;
	TF0 = 0;
  }
  break;
  case 'D':
    for (i=0;i<c;i++)
  {
	TH0 = 0xE7;
	TL0 = 0x74;
	TR0 = 1;
	while (TF0 != 1);
	sound = ~sound;
	TR0 = 0;
	TF0 = 0;
  }
  break;
  case 'C':
    for (i=0;i<c;i++)
  {
	TH0 = 0xE4;
	TL0 = 0x73;
	TR0 = 1;
	while (TF0 != 1);
	sound = ~sound;
	TR0 = 0;
	TF0 = 0;
  }
  break;
  case 'B':
    for (i=0;i<c;i++)
  {
	TH0 = 0xF1;
	TL0 = 0x67;
	TR0 = 1;
	while (TF0 != 1);
	sound = ~sound;
	TR0 = 0;
	TF0 = 0;
  }
  break;
  }
  }
  void sounddelay()
 {
	   for(k = 0; k < 30000; k++)
	   {}
	}
void menu()
{
	ok=0;
	if (amberB!=1)
	{

	  sounddelay();
	  tune1();
	}
	if (yellowB2!=1)
	{
	  tune2();
	}
	if(redB!=1)
	{
	  keyboard();
	}
	if (greenB!=1)
	{
	 snake();
	 }
	if (blueB !=1)
	{
	 cop();
	}
	} 
 void tune2()
 {
   ES=1;
   for(csn=0;csn<12;csn++)
	 {
	 uart_transmit(sn[csn]);
   	 }
   for(z=0;z<21;z++)
   {
   	  twoOn();
	  sounddelay();
	  sounddelay();
	  Slights(z%11);
	  playsound(song2[z],sing2[z]);
	  sounddelay();
	  sounddelay();
	    if(ok==1)
	  {
	   z=21;
	   }
   }
}

void twoOn()		
{
 	  yellowL = 1;
  	  yellowB2 = 1;
	  amberB2 = 1;
     redB=0;
	 yellowB=1;
	 greenB=0;
	 greenL2=1;
	 greenB2=1;
	 blueB=0;

	 sounddelay();
	 sounddelay();
	 sounddelay();
	  yellowB2 = 1;
	  amberB2 = 1;
     redB=1;
	 yellowB=1;
	 greenB=1;
	 greenL2=0;
	 greenB2=1;
	 redB2=1;
	 blueB=1;
}

void oneOn()
{
	  yellowB2 = 1;
	  amberB2 = 1;
     redB=0;
	 yellowB=0;
	 greenB=0;
	 amberL=0;
	 greenB2=0;
	 blueB=0;
	 yellowL=0;
	 sounddelay();
	 sounddelay();
	 sounddelay();
	  yellowB2 = 1;
	  amberB2 = 1;
     redB=1;
	 yellowB=1;
	 greenB=1;
	 amberL=1;
	 greenB2=1;
	 redB2=1;
	 blueB=1;
	 yellowL=1;
}	

void keyboard()
{ 
	redL=0;
	yellowL=0;
	greenL=0;
	amberL=0;
	blueL=0;
	redL2=0;
	yellowL2=0;
	greenL2=0;
	amberL2=0;
	sounddelay();
	cleareverything();
 
	while(amberB2)
	{
		if(yellowB==0)
		{
		 	Lights(2);
			playsound('A',200);
		}
		else if(greenB2==0)
		{
			Lights(8);
			playsound('E',200);
		}
		else if(amberB==0)
		{
			Lights(4);
			playsound('C',200);
		}
		else if(blueB==0)
		{
			Lights(6);
			playsound('D',200);
		}
	} 


}
void Lights(char x)
{
cleareverything();
	if(x==2)
		yellowL=0;
	else if(x==4)
		amberL=0;
	else if(x==6)
		blueL=0;
	else if(x==8)
		greenL2=0;
}
void cleareverything()
{
redL=1;
	yellowL=1;
	greenL=1;
	amberL=1;
	blueL=1;
	redL2=1;
	yellowL2=1;
	greenL2=1;
	amberL2=1;
}

void Slights(int x)
{
cleareverything();
switch(x){
case 0:
cleareverything();
greenL=0;
redL2=0;
amberL2=0;
break;
case 1:
cleareverything();
yellowL=0;
blueL=0;
greenL2=0;
break;
case 2:
cleareverything();
blueL=0;
redL=0;
amberL2=0;
break;
case 3:
cleareverything();
redL2=0;
blueL=0;
amberL=0;
break;
case 4:
cleareverything();
greenL=0;
blueL=0;
yellowL2=0;
break;
case 5:
cleareverything();
redL=0;
amberL=0;
yellowL2=0;
break;
case 6:
cleareverything();
redL=0;
amberL=0;
yellowL2=0;
greenL2=0;
amberL2=0;
break;
case 7:
cleareverything();
redL=0;
amberL=0;
yellowL2=0;
greenL2=0;
amberL2=0;
redL2=0;  
greenL=0;
break;
case 8:
cleareverything();
redL=0;
amberL=0;
yellowL2=0;
greenL2=0;
amberL2=0;
redL2=0;  
greenL=0;
yellowL=0;
break;
case 9:
cleareverything();
redL=0;
blueL=0;
amberL2=0;
greenL=0;
yellowL2=0;
break;
case 10:
cleareverything();
yellowL=0;
blueL=0;
greenL2=0;
redL2=0;
amberL=0;
break;
}
}

void snake()
{

	redL2=0;

	playsound('A',100);
	amberL2=0;
	delay();
	greenL2=0;

	playsound('A',100);
	delay();
	yellowL2=0;
	amberL2=1;

	playsound('A',100);
	delay();
	amberL=0;
	greenL2=1;

	playsound('A',100);
	delay();
	blueL=0;
	yellowL2=1;

	playsound('A',100);
	delay();

	playsound('B',100);
	delay();
	greenL=0;
	amberL=1;

	playsound('A',100);
	delay();
	yellowL=0;
	blueL=1;

	playsound('A',100);
	delay();
	redL=0;
	redL2=1;

	playsound('A',100);
	delay();
	greenL=1;

	playsound('A',100);
	delay();
	yellowL=1;

	playsound('A',100);
	delay();
	redL=1;
}



void delay()
{  
	long signed int i;
	for(i=0;i<40000;i++){}
} 

void cop(){
for ( repeat=0; repeat < 6; repeat++)
{
redL2 = 0;
playsound('D',30);


redL2 = 1;
blueL = 0;
playsound('A',30);

blueL = 1;
}

for ( repeat=0; repeat < 4; repeat++)
{
yellowL = 0;
redL2 = 0;
greenL2 = 0;
amberL = 0;
playsound('D',200);


yellowL = 1;
redL2 = 1;
greenL2 = 1;
amberL = 1;
redL = 0;
greenL = 0;
amberL2 = 0;
yellowL2 = 0;
playsound('A',200);

redL = 1;
greenL = 1;
amberL2 = 1;
yellowL2 = 1;
}

for ( repeat=0; repeat < 4; repeat++)
{
redL2 = 0;
playsound('D',200);


redL2 = 1;

blueL = 0;
playsound('A',200);

blueL = 1;
}
cleareverything();
}