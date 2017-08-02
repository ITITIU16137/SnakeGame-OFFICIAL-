#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>
using namespace std;
//----------------------------------------Declaration----------------------------------------------------
const int H=20;
const int W=40;
int tail[H*W];
bool gameRunning=true;
void drawHead(int x)
{
    box[x]=head;
}
void changeDirection(char key)
{
    //box[position]=' ';
    switch(key)
    {
    case 'w':
        while(kbhit()!=1 && gameRunning)
        {
            redrawScreen();
            UP();
        }
    case 's':
        while(kbhit()!=1 && gameRunning)
        {
            redrawScreen();
            DOWN(position);
        }
    case 'd':
        while(kbhit()!=1 && gameRunning)
        {
           redrawScreen();
           RIGHT(position);
        }
    case 'a':
        while(kbhit()!=1 && gameRunning)
        {
            redrawScreen();
            LEFT(position);
        }
    }
}
void makeTail()
{
    for(int i=0;i<W*H;i++)
    {
        if(tail[i]>0)
        {
            tail[i]++;
        }
        if(tail[i]==score+2)
        {
            tail[i]=0;
        }
    }
}
int main()
{
    drawHead(position);
    tail[position]=1;
     for(int i=0;i<H*W;i++)
    {
        tail[i]=0;
    }

    while(position>=W && position<=H*W-W && position%W!=0 && (position+1)%W!=0)
    {
        if(kbhit())
        {
            changeDirection(getch());
        }
    }
    system("pause");
    return 0;
}
