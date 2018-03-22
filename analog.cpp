#include <graphics.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
#include <iostream>
#include <ctime>



#define S_N_L (radius-10)
#define S_N_C RED
#define M_N_L (radius-20)
#define M_N_C LIGHTRED
#define H_N_L (radius-(radius/2))
#define H_N_C CYAN

using namespace std;

float cx,cy;
float radius=100;


void draw_face(float radius)
{

int theta=0;
float x,y;

circle(cx,cy,radius+24);
circle(cx,cy,radius+23);

setcolor(LIGHTGREEN);

for(int i=0;i<9;i++)
circle(cx,cy,radius+13+i);

setcolor(15);

circle(cx,cy,radius+12);
circle(cx,cy,radius+10);

circle(cx,cy,2);
int i=0;

do{

x=cx+radius*cos(theta*M_PI/180);
y=cy+radius*sin(theta*M_PI/180);

circle(x,y,2);

circle(x+5,y,1);
circle(x-5,y,1);
circle(x,y+5,1);
circle(x,y-5,1);

theta+=30;

i++;

}
while(i!=12);
i=0;

do{
putpixel(cx+radius*cos(i*M_PI/180),cy+radius*sin(i*M_PI/180),15);
i+=6;
}while(i!=360);


}

void get_time(int &h,int &m,int &s)
{
time_t rawtime;
struct tm *t;
time(&rawtime);
t = gmtime(&rawtime);
h=t->tm_hour;
m=t->tm_min;
s=t->tm_sec;
}

void second_needle(int s)
{

float angle=90;
float sx,sy;
setcolor(25);
sx=cx+S_N_L*cos((angle+(s-30)*6-6)*M_PI/180);
sy=cy+S_N_L*sin((angle+(s-30)*6-6)*M_PI/180);
line(cx,cy,sx,sy);

setcolor(S_N_C);
sx=cx+S_N_L*cos((angle+(s-30)*6)*M_PI/180);
sy=cy+S_N_L*sin((angle+(s-30)*6)*M_PI/180);
line(cx,cy,sx,sy);
}

void minute_needle(int m,int s)
{
float angle=90;
float sx,sy;

setcolor(25);
sx=cx+M_N_L*cos((angle+m*6-6)*M_PI/180);
sy=cy+M_N_L*sin((angle+m*6-6)*M_PI/180);
line(cx,cy,sx,sy);

setcolor(M_N_C);
sx=cx+M_N_L*cos((angle+m*6/*+(s*6/60)*/)*M_PI/180);
sy=cy+M_N_L*sin((angle+m*6/*+(s*6/60)*/)*M_PI/180);
line(cx,cy,sx,sy);

}


void hour_needle(int h,int m,int s)
{
float angle=90;
float sx,sy;
setcolor(25);
sx=cx+H_N_L*cos((angle+h*30-30/*-(m*30/60)*/)*M_PI/180);
sy=cy+H_N_L*sin((angle+h*30-30/*-(m*30/60)*/)*M_PI/180);
line(cx,cy,sx,sy);
setcolor(H_N_C);
sx=cx+H_N_L*cos((angle+h*30/*+(m*30/60)*/)*M_PI/180);
sy=cy+H_N_L*sin((angle+h*30/*+(m*30/60)*/)*M_PI/180);
line(cx,cy,sx,sy);
}

void dis()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        system("color F3");
        cout <<"===============================================================\n";
        cout <<"\t\t\t TITAN'S ALARM\n";
        cout <<"---------------------------------------------------------------\n\n";
        cout << "Time : "<< ltm->tm_hour << ":";
        cout << ltm->tm_min << ":";
        cout << ltm->tm_sec;

        char date[9];
        _strdate(date);
	    cout <<"\t\t\t\t\tDate : "<< date << endl;
    }


int main(void)
{
system("color F3"); dis();
int s;cout<<"Enter\n1: Set alarm\n";
cout<<"2: Exit\n";
cin>>s;
if(s==1)
{
    system("start main.exe");
}
else
 {
    cout<<"Invalid Choice.";
    exit(1);
 }
int gdriver = DETECT, gmode, errorcode;
initwindow(600,800,"TITAN'S CLOCK");
setfillstyle(SOLID_FILL,25);
setcolor(25);
rectangle(50,50,50,50);
floodfill(51,51,6);


cx=getmaxx()/2.0;
cy=getmaxy()/2.0;

settextstyle(BOLD_FONT,HORIZ_DIR,5);
setcolor(15);
outtextxy(150,10,"TITAN'S ALARM");

float x,y;
int hour,minute,second;
draw_face(radius);
while(!kbhit())
{
get_time(hour,minute,second);
second_needle(second);
minute_needle(minute,second);
hour_needle(hour,minute,second);
circle(cx,cy,2);
delay(100);
}

getch();
closegraph();
return 0;
}
