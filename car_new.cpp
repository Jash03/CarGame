#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
void floodfill(int x,int y,int fill,int old)
{
if(getpixel(x,y)==old)
{
putpixel(x,y,fill);
floodfill(x+1,y,fill,old);
floodfill(x-1,y,fill,old);
floodfill(x,y+1,fill,old);
floodfill(x,y-1,fill,old);
}
}
void boundaryfill(int x,int y,int fill,int old)
{
if((getpixel(x,y)!=old)&&(getpixel(x,y)!=fill))
{
putpixel(x,y,fill);
boundaryfill(x+1,y,fill,old);
boundaryfill(x-1,y,fill,old);
boundaryfill(x,y-1,fill,old);
boundaryfill(x,y+1,fill,old);
}
}
void car(int xc,int yc,int colour,int bcolour)
{
int xcor,ycor;
xcor=xc-10;
ycor=yc-15;
line(xcor,ycor,xcor+20,ycor);
line(xcor,ycor+30,xcor+20,ycor+30);
line(xcor,ycor,xcor,ycor+30);
line(xcor+20,ycor,xcor+20,ycor+30);
/*line(xcor,ycor,xcor+10,ycor-5);
line(xcor+10,ycor-5,xcor+20,ycor);*/
line(xcor,ycor+5,xcor-3,ycor+5);
line(xcor,ycor+13,xcor-3,ycor+13);
line(xcor-3,ycor+5,xcor-3,ycor+13);
line(xcor,ycor+18,xcor-3,ycor+18);
line(xcor,ycor+26,xcor-3,ycor+26);
line(xcor-3,ycor+18,xcor-3,ycor+26);
line(xcor+20,ycor+5,xcor+23,ycor+5);
line(xcor+20,ycor+15,xcor+23,ycor+15);
line(xcor+23,ycor+5,xcor+23,ycor+15);
line(xcor+20,ycor+18,xcor+23,ycor+18);
line(xcor+20,ycor+26,xcor+23,ycor+26);
line(xcor+23,ycor+18,xcor+23,ycor+26);
boundaryfill(xc,yc,colour,bcolour);
/*boundaryfill(xcor+10,ycor-2,colour,bcolour);*/
}
void background()
{
int i,j;
line(100,0,100,480);
line(100,0,640,0);
line(639,0,639,480);
line(100,479,640,479);
line(280,0,280,480);
line(460,0,460,480);
line(639,0,639,480);
for(i=100;i<640;i++)
{
if(i<280||i>460)
{
for(j=0;j<480;j++)
{
putpixel(i,j,GREEN);
}
}
}
for(i=365;i<375;i++)
{
for(j=0;j<480;j++)
{
if((j>0&&j<60)||(j>75&&j<135)||(j>150&&j<210)||(j>225&&j<285)||(j>300&&j<360)||(j>375&&j<435)||(j>450&&j<510))
putpixel(i,j,WHITE);
}
}
}
void clear(int x,int y)
{
car(x,y,BLACK,BLACK);
sound(300);
delay(150);
nosound();
}
void obstacles()
{
car(320,120,CYAN,WHITE);
car(410,40,MAGENTA,WHITE);
car(320,280,DARKGRAY,WHITE);
car(320,360,LIGHTBLUE,WHITE);
car(410,440,YELLOW,WHITE);
car(410,200,BROWN,WHITE);
}
void main()
{
int i,j,x=320,y=440,totalmove=0,col;
char choice,forexit;
int gm,gd=DETECT;
initgraph(&gd,&gm," ");
do
{
background();
for(i=0;i<5;i++)
{
sound(200);
delay(100);
sound(100);
delay(100);
nosound();
}
obstacles();
car(x,y,RED,WHITE);
outtextxy(0,20,"D for right");
outtextxy(0,40,"A for left");
outtextxy(0,60,"W for front");
outtextxy(0,80,"S for reverse");
outtextxy(0,100,"SPACEBAR for finish");
circle(25,200,10);
boundaryfill(25,200,RED,WHITE);
sound(1000);
delay(750);
nosound();
delay(750);
floodfill(25,200,BLACK,RED);
circle(55,200,10);
boundaryfill(55,200,YELLOW,WHITE);
sound(1000);
delay(750);
nosound();
delay(750);
floodfill(55,200,BLACK,YELLOW);
circle(85,200,10);
boundaryfill(85,200,GREEN,WHITE);
sound(1000);
delay(750);
nosound();
delay(750);
floodfill(85,200,BLACK,GREEN);
sound(1200);
delay(1000);
nosound();
while(y>60)
{
choice=getch();
if(choice==' ')
{
getch();
closegraph();
}
if((x==320&&y==120)||(x==320&&y==280)||(x==320&&y==360)||(x==410&&y==40)||(x==410&&y==440)||(x==410&&y==200))
{
clear(x,y);
for(i=1;i<15;i++)
{
setcolor(YELLOW);
circle(x,y,i);
setcolor(WHITE);
}
floodfill(x,y,YELLOW,BLACK);
y=20;
outtextxy(300,240,"\nCRASHED");
for(i=150;i>30;i=i-20)
{
sound(i);
delay(100);
nosound();
}
}
else if((x<300&&x>450)&&(y<25&&y>460))
{
printf("Drive on road");
}
else
{
if(choice=='d'||choice=='D')
{
clear(x,y);
x=x+90;
car(x,y,RED,WHITE);
}
if(choice=='A'||choice=='a')
{
clear(x,y);
x=x-90;
car(x,y,RED,WHITE);
}
if(choice=='W'||choice=='w')
{
clear(x,y);
y=y-40;
car(x,y,RED,WHITE);
}
if(choice=='S'||choice=='s')
{
clear(x,y);
y=y+40;
car(x,y,RED,WHITE);
}
}
totalmove++;
}
if(y!=20)
{
outtextxy(300,240,"\nDESTINATION REACHED");
for(i=1500,j=800;i>1400;i=i-20)
{
sound(i);
delay(100);
sound(j);
j=j-50;
delay(100);
nosound();
}
}
x=320;
y=440;
i=0;
j=0;
totalmove=0;
cleardevice();
}while((choice!=' ')||(choice!='k'));
}