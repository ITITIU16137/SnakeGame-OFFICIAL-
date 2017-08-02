#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>
using namespace std;
//----------------------------------------Declaration----------------------------------------------------
const int H=20;
const int W=40;
const int speed=50;
int tail[H*W];
bool gameRunning=true;

void ShowConsoleCursor(bool showFlag); // to hide the cursor
void gotoxy(int x, int y);
int UP();
int DOWN(int &x);
int RIGHT(int &x);
int LEFT(int &x);         // to move the cursor to the beginning place
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//----------------------------------------Headers--------------------------------------------------------

int main()
{
    SetConsoleTextAttribute(hConsole, 11);
    ShowConsoleCursor(false);
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
    gotoxy(55,14);
    cout<<"   Game Over!!!!!!!"<<endl;
    gotoxy(0,25);
    system("pause");
    return 0;
}
//---------------------------------------------------------------------------------------------------------------
void gotoxy(int x, int y) {
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
//---------------------------------------------------------------------------------------------------------------
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
//--------------------------------------------
int UP()
{
   position=position-W;
}

int DOWN(int &x)
{
    x=x+W;
}

int RIGHT(int &x)
{
    x=x+1;
}

int LEFT(int &x)
{
    x=x-1;
}
