#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<stdio.h>
#include<graphics.h>

void maze()
{ textcolor(8);
  for(int i=1;i<3;i++)
    {
	for (int j=1;j<26;j++)
	{
		gotoxy(i,j);
		printf("*");
	}
    }

    for (i=3;i<79;i++)
    {
	for(int j=1;j<3;j++)
	{
	gotoxy(i,j);
	printf("*");
	}
    }

    for(i=79;i<81;i++)
    {
	for(int j=1;j<25;j++)
	{
	gotoxy(i,j);
	printf("*");
	}
    }

   for (i=3;i<80;i++)
    {
	for(int j=24;j<26;j++)
	{
	gotoxy(i,j);
	printf("*");
	}
    }



}

int check(float x,float y)
{ int b=0;
  for(int i=1;i<3;i++)
    {
	for (int j=1;j<26;j++)
	{
		if(x==i&&y==j)
		b++;
	}
    }

    for (i=3;i<79;i++)
    {
	for(int j=1;j<3;j++)
	{
	if(x==i&&y==j)
	b++;
	}
    }

    for(i=79;i<81;i++)
    {
	for(int j=1;j<25;j++)
	{
	if(x==i&&y==j)
	b++;
	}
    }

   for (i=3;i<80;i++)
    {
	for(int j=24;j<26;j++)
	{
	if(x==i&&y==j)
	b++;
	}
    }


		return b;

}

int checkd(int x[],int y[],int h,int k)
{    int b=0;
	for( int i=0;x[i]!=0&&y[i]!=0;i++)
	{if(x[i]==h&&y[i]==k)
		 b++;}
      return b;}
void main()
{   clrscr();
   textmode(C40);
    gotoxy(1,1);
textcolor(1);
cprintf("Developed by:");
gotoxy(1,2);
textcolor(7);
cprintf("Alabhya, Atul, Rahul, Pranjal");
gotoxy(1,3);textcolor(1);
cprintf("Class:");
textcolor(7);
cprintf("XI L");
textcolor(4);
gotoxy(2,10);
cprintf("S N A K E");
	for(int i=0;i<1;i++)
	  {

		textcolor(2);
		gotoxy(12,16);
		cprintf("LOADING");
		gotoxy(10,18);
		delay(400);
		sound(250);
		delay(700);
		cout<<" . ";
		sound(210);
		delay(300);
		sound(170);
		delay(700);
		cout<<" . ";
		sound(300);
		delay(300);
		sound(111);
		delay(700);
		cout<<" . ";
		sound(410);
		delay(700);
		cout<<" . ";
		sound(600);
		delay(300);
		sound(140);
		delay(700);
		cout<<" . ";
		sound(324);
		delay(300);
		sound(435);
		delay(700);
		cout<<" . ";
		sound(234);
		delay(300);
		sound(69);
		delay(700);
		cout<<" . ";
		sound(114);
		delay(700);
		cout<<" . ";
		sound(245);
		delay(300);
		nosound();
	  }           clrscr();
textmode(C40);
gotoxy(12,8);
char z[20];
textcolor(3);
cprintf("Enter Player Name \n");
gotoxy(15,10);
textcolor(3);
gets(z);
randomize();
clrscr();
textmode(C80);
maze();
int a=22,b=22,exit=0,n=4,temp;
char ch=75;
int cs=1,cf=1;
int x[2000]={52,53,54,55,56};
int  y[2000]={18,18,18,18,18};
    while(ch!=27&&exit==0)
     {
		if(kbhit())
		ch=getch();
		if(temp==72&&(ch!=77&&ch!=75&&ch!=27&&ch!=13))
		ch=temp;
		if(temp==80&&(ch!=77&&ch!=75&&ch!=27&&ch!=13))
		ch=temp;
		if(temp==77&&(ch!=72&&ch!=80&&ch!=27&&ch!=13))
		ch=temp;
		if(temp==75&&(ch!=72&&ch!=80&&ch!=27&&ch!=13))
		ch=temp;
		for(int i=0;x[i]!=0||y[i]!=0;i++);
				 for(int p=i-1;p>0;p--)//executes from last set of coordinates and shift them to previous set of coordinates(motion principle of the snake)
				 {	x[p]=x[p-1];
					y[p]=y[p-1];
				 }
		switch (ch)
		{case 72:
				 y[0]--;                    //up decrement in y coordinate
				 for( i=0;x[i]!=0||y[i]!=0;i++)
				 { if(y[i]<1)
				    y[i]=24;
				 }	temp=ch; //stores the lates direction of snake
				 break;
			case 80:

				 y[0]++;               //down increment in  y coordinate
				for(i=0;x[i]!=0||y[i]!=0;i++)
			       {
				 if(y[i]>24)            //prevents the set of coordinates from being out of range of screen coordinates
				 y[i]=1;                //snake paases through border and emerges from other side
			       }

					temp=ch;
				 break;
			case 75:

				 x[0]--;            //left decrement in x coordinate
				 for(i=0;x[i]!=0||y[i]!=0;i++)
				 {
				 if(x[i]<1)
				 x[i]=80;
				 }

					temp=ch;
				 break;
			case 77:

				 x[0]++;                    //right increment in x coordinate
				 for(i=0;x[i]!=0||y[i]!=0;i++)
				 {
				 if(x[i]>80)
				 x[i]=1;}

					temp=ch;
				 break;
				 case 13:getch(); //pauses by waiting for input
					 ch=temp; //restores the snakes original direction of motion
					 break;

	}

	if(x[0]==a && y[0]==b) //coordinates of food
		{	n++; //increases the snakes length
			switch (ch)
			{
			  case 72: x[n]=x[n-1];   //values for the newly added set of coordinates depending on the direction of motion
				   y[n]=y[n-1]+1;
				   break;
			  case 80 :x[n]=x[n-1];
				   y[n]=y[n-1]-1;
				   break;
			  case 75 :x[n]=x[n-1]+1;
				   y[n]=y[n-1];
				   break;
			  case 77:x[n]=x[n-1]-1;
				   y[n]=y[n-1];
				   break;
			} do
		       {
			 a=random(80);  // new set of coordinates of food
			b=random(25);}
		       while (a==0||b==0||(a>0&&a<10&&b==1)||(checkd(x,y,a,b)>0)||check(a,b)>0); //prevents the new set of coordinates from being out of range or on the snake

		}
		  if(ch!=27)
	       {  if(checkd(x,y,x[0],y[0])>1||check(x[0],y[0])>0)
		    exit++	;} //matches the coordinates of head of snake with itself returns 2 if it matches else returns 1 because coordinates of head always matches with itself,-1 to prent exit of loop
		textcolor(8);
		gotoxy(a,b);
			cprintf("%c",4);       //displays food
			 cf++;
			 if(cf==14)
			 cf=1;
			 textcolor(cs)  ;
			 gotoxy(x[0],y[0]);
			cprintf("%c",9);           //displays snake head

		for(  i=1;x[i]!=0;i++)
		{ textcolor(3);
		gotoxy(x[i],y[i]);
	       cprintf("%c",4);      //displays rest of the body
		cs++;
		if(cs==14)
		cs=1;
		}
		gotoxy(1,1);
		textcolor(6);
		 cprintf(z);
		  gotoxy(72,1);
		 cprintf("score=");cprintf("%i",(n-4));
		textcolor(6);
		 delay(100);
		 for(i=0;x[i]!=0;i++)
	{	gotoxy(x[i],y[i]);
		cout<<" ";}         //erases the diplayed snake
}
if (exit>0)
{
clrscr();
gotoxy(36,13);
puts(z);
gotoxy(36,15);
cout<<"GAME OVER";
gotoxy(36,17);
cout<<"SCORE:"<<n-4;
}
getch();
}