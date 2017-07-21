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
int foodPos=0;
char box[H*W];
int tail[H*W];
int position=H*W/2-W/2;
int score=0;
bool gameRunning=true;
char food = char(254), head= char(219),Tail=char(176);
char hrz=char(205),vtc=char(186),agl1=char(201),agl2=char(187),agl3=char(200),agl4=char(188);
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//----------------------------------------Headers--------------------------------------------------------
void mapDesign();
void scoreScreen();
void scoreCount();
void ShowConsoleCursor(bool showFlag); // to hide the cursor
void gotoxy(int x, int y);             // to move the cursor to the beginning place
void mapScreen();
void redrawScreen();
void checkGame();
void foodRand();
void makeTail();

int UP();
int DOWN(int &x);
int RIGHT(int &x);
int LEFT(int &x);

void drawHead(int x);
void changeDirection(char key);
//-----------------------------------------Run Program--------------------------------------------------
int main()
{
    SetConsoleTextAttribute(hConsole, 11);
    ShowConsoleCursor(false);
    mapDesign();
    drawHead(position);
    mapScreen();
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
    //cout<<tail[H*W/2-W/2]<<endl;
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

void scoreScreen()
{
    gotoxy(60,10);
    cout<<"Score: "<<score;
}

void scoreCount()
{
    if(position==foodPos)
    {
        score++;
    }
}
//-------------------------------------------------------------------------------------------------------------
void checkGame()
{
    if(position>=W && position<=H*W-W && position%W!=0 && (position+1)%W!=0)
    {
        gameRunning=true;
    }
    else
    {
        gameRunning=false;
    }
}

void mapDesign()
{
    scoreCount();
    foodRand();
    box[foodPos]=food;
    scoreScreen();

    gotoxy(0,0);

    for(int i=0;i<H*W;i++)
    {
        if(i<W || i>H*W-W-1) // i%W==0 || (i+1)%W==0)
        {
            box[i]=hrz;
        }
        if(i%W==0 || (i+1)%W==0)
        {
            box[i]=vtc;
        }
        box[0]=agl1;
        box[W-1]=agl2;
        box[H*W-W]=agl3;
        box[H*W-1]=agl4;
    }
    if(position==foodPos)
    {
        foodRand();
    }
}

void mapScreen()
{
    for(int i=0;i<H*W;i++)
    {
        if(i==position)
        {
            SetConsoleTextAttribute(hConsole, 12);
        }
        if(i<W || i>H*W-W || (i)%W==0 || (i+1)%W==0)
        {
            SetConsoleTextAttribute(hConsole, 10);
        }
        if(i==foodPos)
        {
            SetConsoleTextAttribute(hConsole, 14);
        }
        cout<<box[i];
        SetConsoleTextAttribute(hConsole, 11);
        if((i+1)%W==0)
        {
            cout<<endl;
        }

    }
}

void drawHead(int x)
{
    box[x]=head;
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
//----------------------------------------------
void redrawScreen()
{
    mapDesign();
    checkGame();
    Sleep(speed);
    gotoxy(0,0);
    drawHead(position);
    mapScreen();
    tail[position]=1;
    makeTail();
    for(int i=0;i<H*W;i++)
    {
        if(tail[i]==0)
        {
            box[i]=' ';
        }
        else
        {
            box[i]=Tail;
        }
    }

    //box[position]=' ';
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

void foodRand()
{
    while(foodPos<W || foodPos>H*W-W || foodPos%W==0 || (foodPos+1)%W==0 || position==foodPos || tail[foodPos]>0)
    {
        srand(time(NULL));
        foodPos=rand()%(H*W);
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
