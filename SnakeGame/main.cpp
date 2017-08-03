#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include "menuStart.h"
#include "setConsole.h"
#include "Sound.h"
#include "EndScreen.h"
using namespace std;
//----------------------------------------Declaration----------------------------------------------------
const int H = 20;
const int W = 40;
const int speed = 50;
int foodPos = 0;
char box[H*W];
int tail[H*W];
int position = H*W/2-W/2;
int score = 0;
bool gameRunning = true;
char food = 254, head = 219,Tail = 176;
char hrz = 205,vtc = 186,agl1 = 201,agl2 = 187,agl3 = 200,agl4 = 188;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
DWORD WINAPI GetTickCount();
//----------------------------------------Headers--------------------------------------------------------
void mapDesign();
void scoreScreen();
void scoreCount();
void ConsoleSetup();
void mapScreen();
void redrawScreen();
void checkGame();
void foodRand();
void makeTail();

int UP(int &x);
int DOWN(int &x);
int RIGHT(int &x);
int LEFT(int &x);

void drawHead(int x);
void changeDirection(char key);
//-----------------------------------------Run Program--------------------------------------------------
int main()
{
    menuStart();
    system("cls");

    playSound("a.wav",1);
    SetConsoleTextAttribute(hConsole,11); //blue
    ShowConsoleCursor(false);
    //ConsoleSetup();
    gotoxy(50,0);
    cout << " ____  __ _   __   __ _  ____     ___   __   _  _  ____ \n";
    gotoxy(50,1);
    cout << "/ ___)(  ( \\ / _\\ (  / )(  __)   / __) / _\\ ( \\/ )(  __)\n";
    gotoxy(50,2);
    cout << "\\___ \\/    //    \\ )  (  ) _)   ( (_ \\/    \\/ \\/ \\ ) _) \n";
    gotoxy(50,3);
    cout << "(____/\\_)__)\\_/\\_/(__\\_)(____)   \\___/\\_/\\_/\\_)(_/(____)";
    mapDesign();
    drawHead(position);
    mapScreen();
    tail[position]=1;

    for(int i=0; i<H*W ; i++)
    {
        tail[i]=0;
    }

    while(gameRunning)
    {
        if(kbhit())
        {
            changeDirection(getch());
        }
    }
    Sleep(2000);
    system("cls");
   if(!gameRunning)
   {
       EndScreen();
   }
    // gotoxy(55,20);
    //cout<<"   GAME OVER!!!!!!!"<<endl;
    gotoxy(0,25);
    system("pause");
    return 0;
}
//----------------------------------------------------------End of Run Program---------------------------------------------------
//----------------------------------------------------------Control Snake--------------------------------------------------------
void changeDirection(char key)
{
    switch(key)
    {
    case 'w':
        while(kbhit()!=1 && gameRunning)
        {
            redrawScreen();
            UP(position);
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
//----------------------------------------------------------Print again after moving---------------------------------------------------
void redrawScreen()
{
    mapDesign();
    checkGame();
    tail[position]=1;
    //checkGame();
    Sleep(speed);
    gotoxy(0,0);
    drawHead(position);
    makeTail();
    mapScreen();
    //tail[position]=1;
    //makeTail();
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



//---------------------------------------------------Check the condition of snake if snake---------------------------------------
void checkGame()
{
    for(int i=0; i<H*W; i++)                // crash tail will die
    {
        if(tail[i]>1 && i==position)
        {
            gameRunning=false;
        }
    }

    if(position<W || position>H*W-W || position%W==0 || (position+1)%W==0)   //  crash wall will die
    {
        gameRunning=false;
    }

}
//--------------------------------------------------------------Create All Elements-----------------------------------------------
void mapDesign()
{
    scoreCount();
    foodRand();
    box[foodPos]=food;
    scoreScreen();

    gotoxy(0,0);

    for(int i=0; i<H*W; i++)
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
}
//-----------------------------------------------------Print all element on screen and set color------------------------------
void mapScreen()
{
    for(int i=0; i<H*W; i++)
    {
        if(i==position)
        {
            SetConsoleTextAttribute(hConsole, 12); //red
        }
        if(i<W || i>H*W-W || (i)%W==0 || (i+1)%W==0)
        {
            SetConsoleTextAttribute(hConsole, 10); //green
        }
        if(i==foodPos)
        {
            SetConsoleTextAttribute(hConsole, 14); //yellow
        }
        cout<<box[i];
        SetConsoleTextAttribute(hConsole, 11); //light cyan
        if((i+1)%W==0)
        {
            cout<<endl;
        }

    }
}
//----------------------------------------------------Set initial Position of Snake---------------------------
void drawHead(int x)
{
    box[x]=head;
}
//---------------------------------------------------Food random----------------------------------------------------------
void foodRand()
{
    while(foodPos<W || foodPos>H*W-W || foodPos%W==0 || (foodPos+1)%W==0 || position==foodPos || tail[foodPos]>0)
    {
        //foodPos=0;
        srand(GetTickCount());
        foodPos=rand()%(H*W);
    }
}
//-------------------------------------------------------Tail Longger-----------------------------------------------------
void makeTail()
{
    for(int i=0; i<W*H; i++)
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

//-----------------------------------------------------------------------------------------------------------
int UP(int &x)
{
   x=x-W;
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


//--------------------------------------------ScoreBoard-------------------------------------------------------------------

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
/*void ConsoleSetup ()
{
    HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);    // Write on console
    HANDLE rHnd = GetStdHandle(STD_INPUT_HANDLE);    // Read from console
    CONSOLE_CURSOR_INFO cursorInfo;
}*/
/*void gotoxy(int x, int y) {
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
}*/


