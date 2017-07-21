#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int const width=40;
int const height=20;
int headPos=(height*width)/2+width/2;//ran nam giua khung
char head=char(219);
char wall[width*height];
int x=1;
bool gameStart=true;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//-------------------------Khai bao cac ham su dung----------------------------------
void Create();
void makeWall();
void screenMap();
void UP(int &x);
void DOWN(int &x);
void LEFT(int &x);
void RIGHT(int &x);
void changeDirection();
void gotoXY(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	_COORD pos;
	pos.X = x;                                                  //Set gotoXY
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
}
void ShowConsoleCursor(bool showFlag)
{
    HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(wHnd, &cursorInfo);
    cursorInfo.bVisible = showFlag;                               // set the cursor visibility
    SetConsoleCursorInfo(wHnd, &cursorInfo);
}
//MAINNNN
int main()
{   ShowConsoleCursor(false);
    Create();
	makeWall();
    while (gameStart!=true)
	{
	screenMap();
	RIGHT(headPos);
	screenMap();
	DOWN(headPos);
	screenMap();
	LEFT(headPos);
	screenMap();
	UP(headPos);
	/*changeDirection();*/
	}
}
void Create(){
    wall[headPos]=head;                             //Create Snake
}
void makeWall()
{
	for (int i = 0; i<width*height; i++)
	{
		if (i<width || i>(width*height - width) || i%width == 0 || (i + 1) % width == 0)            //Create Wall
		{
			wall[i] = '*';
        }

	}
}
void screenMap()
{
	for (int i = 0; i <= height*width; i++)
	{
		cout << wall[i];                                                    //Print Screen
		if ((i + 1) % width == 0) {
			cout << endl;
		}
	}
	Sleep(500);
	wall[headPos]=head;
	gotoXY(0,0);

}

void UP(int &x)
{
	x = x - width;
}
void DOWN(int &x)
{
    x= x + width;
}
void RIGHT(int &x)                                  //Trang thai UP,DOWN,RIGHT,LEFT
{
    x = x + 1;
}
void LEFT(int &x)
{
    x = x - 1;
}

/*void changeDirection(char key)
{	if (_kbhit())
	switch (key)
    case 'w':
        while (
		UP(headPos);
	case 'd':
		RIGHT(headPos);
	case 'a':
		LEFT(headPos);
	case 's':
		DOWN(headPos);
	default:
		break;
}
*/


