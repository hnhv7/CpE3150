#include <reg932.h>
#include <uart.h>

//lights display position assigning
sbit Sposition1=P2^4;
sbit Sposition2=P0^5;
sbit Sposition3=P2^7;
sbit Sposition4=P0^6;
sbit Sposition5=P1^6;
sbit Sposition6=P0^4;
sbit Spotision7=P2^5;
sbit Spotision8=P0^7;
sbit Spotision9=P2^6;

//lights input position assigning
sbit MoveUp=P0^1;
sbit MoveDown=P0^3;
sbit MoveLeft=P0^2;
sbit MoveRight=P0^0;
sbit ext=P2^2;

void main()
{
	ext=0;
	//initiate starting point
	Sposition5=0;
	unsigned char position=5;

	while(ext==0)
	{
		if(MoveUp==1)
		{
			ChangePosition(1, position);
		}
		else if(MoveDown==1)
		{
			ChangePosition(2, position);
		}
		else if(MoveLeft==1)
		{
			ChangePosition(3, position);
		}
		else if(MoveRight==1)
		{
			ChangePosition(4, position);
		}
	}
}

char ChangePosition(int MovingPosition, char Position)
{
	if(MovingPosition==1)
	{
		switch (Position)
		{
			case 1:
			flash();
			break;

			case 2:
			flash();
			break;
			
			case 3:
			flash();
			break;

			case 4:
			Position=Position-3;
			break;

			case 5:
			Position=Position-3;
			break;

			case 6:
			Position=Position-3;
			break;

			case 7:
			Position=Position-3;
			break;

			case 8:
			Position=Position-3;
			break;

			case 9:
			Position=Position-3;
			break;

			default:
			flash();
		}
	}
	else if(MovingPosition==2)
	{
		switch (Position)
		{
			case 1:
			Position=Position+3;
			break;

			case 2:
			Position=Position+3;
			break;
			
			case 3:
			Position=Position+3;
			break;

			case 4:
			Position=Position+3;
			break;

			case 5:
			Position=Position+3;
			break;

			case 6:
			Position=Position+3;
			break;

			case 7:
			flash();
			break;

			case 8:
			flash();
			break;

			case 9:
			flash();
			break;

			default:
			flash();
		}
	}
	else if(MovingPosition==3)
	{
		switch (Position)
		{
			case 1:
			flash();
			break;

			case 2:
			Position=Position-1;
			break;
			
			case 3:
			Position=Position-1;
			break;

			case 4:
			flash();
			break;

			case 5:
			Position=Position-1;
			break;

			case 6:
			Position=Position-1;
			break;

			case 7:
			flash();
			break;

			case 8:
			Position=Position-1;
			break;

			case 9:
			Position=Position-1;
			break;

			default:
			flash();
		}
	}
	else if(MovingPosition==4)
	{
		switch (Position)
		{
			case 1:
			Position=Position+1
			break;

			case 2:
			Position=Position+1;
			break;
			
			case 3:
			flash();
			break;

			case 4:
			Position=Position+1;
			break;

			case 5:
			Position=Position+1;
			break;

			case 6:
			flash();
			break;

			case 7:
			Position=Position+1;
			break;

			case 8:
			Position=Position+1;
			break;

			case 9:
			flash();
			break;

			default:
			flash();
		}
	}

	//changing lights
	cleareverything();
	switch (Position)
	{
		case 1:
		Sposition1=1;
		break;

		case 2:
		Sposition2=1;
		break;

		case 3:
		Sposition3=1;
		break;

		case 4:
		Sposition4=1;
		break;

		case 5:
		Sposition5=1;
		break;

		case 6:
		Sposition6=1;
		break;

		case 7:
		Sposition7=1;
		break;

		case 8:
		Sposition8=1;
		break;

		case 9:
		Sposition9=1;
		break;

	}
	return Position;
}

void cleareverything()
{
	Sposition1=1;
	Sposition2=1;
	Sposition3=1;
	Sposition4=1;
	Sposition5=1;
	Sposition6=1;
	Sposition7=1;
	Sposition8=1;
	Sposition9=1;
}

flash()
{
	//lol just kidding, nothing happenes here
}