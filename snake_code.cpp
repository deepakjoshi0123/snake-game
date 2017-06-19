#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
bool finish;
const int width = 50;
const int height =20;

int x,y,ball_x,ball_y,score;
int tailx[100],taily[100];
int ntail;
enum dir{STOP=0,LEFT,RIGHT,UP,DOWN};
dir dir1;
void start()
{
	finish=false;
	dir1=STOP;
	x=width/2;
	y=height/2;
	ball_x=rand()%width;
	ball_y=rand()%height;
	score=0;
}
void makeup_area()
{
	system("cls");
	for(int i=0;i<width+10;i++)
	cout<<"_";
	cout<<endl;
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(j==0)
			cout<<"|";
			if(i==y&&j==x)
			cout<<"o";
			else if(i==ball_y&&j==ball_x)
			cout<<"v";
			else
			{
				bool print=false;
				for(int k=0;k<ntail;k++)
				{
					if(tailx[k]==j&&taily[k]==i)
					{
						cout<<"o";
						print=true;
					}
				}
			if(!print)
			cout<<" ";	
			}
			if(j==width-1)
			cout<<"|";
		}
		cout<<endl;
	}
	for(int i=0;i<width+10;i++)
	cout<<"_";
	cout<<endl;
	cout<<"scores:"<<score<<endl;
	cout<<"controls\nw-up\ns-down\na-left\nd-right";
}
void input()
{
	if(kbhit())
	{
		switch(getch())
		{
			case 'a':
				dir1=LEFT;
				break;
			case 'd':
			    dir1=RIGHT;
				break;
			case 'w':
			    dir1=UP;
				break;
			case 's':
			    dir1=DOWN;
				break;
			case 'x':
				finish = true;
				break;
							
		}
	}
}

void logic()
{
	int prevx=tailx[0];
	int prevy=taily[0];
	int prevzx,prevzy;
	tailx[0]=x;
	taily[0]=y;
	for(int i=1;i<ntail;i++)
	{
		prevzx=tailx[i];
		prevzy=taily[i];
		tailx[i]=prevx;
		taily[i]=prevy;
		prevx=prevzx;
		prevy=prevzy;
	}
	switch(dir1)
	{
		case LEFT:
			x--;
			break;
		case RIGHT:
		    x++;
		    break;
		case UP:
		    y--;
			break;
		case DOWN:
			y++;
			break;
		default:
		    break;			
	}
	if(x>=width)
	x=0;
	else if(x<0)
	x=width-1;
	if(y>=height)
	y=0;
	else if(y<0)
	y=height-1;
	for(int i=0;i<ntail;i++)
	if(tailx[i]==x&&taily[i]==y)
	finish=true;
	if(x==ball_x&&y==ball_y)
	{
		score+=10;
		ball_x=rand()%width;
		ball_y=rand()%height;
		ntail++;
	}
}

int main()
{   
    start();
	while(!finish)
	{
	makeup_area();
	input();
	logic();
	Sleep(200);
   }
   return 0;
}