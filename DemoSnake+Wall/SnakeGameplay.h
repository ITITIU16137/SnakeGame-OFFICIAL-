#ifndef SNAKEGAMEPLAY_H_INCLUDED
#define SNAKEGAMEPLAY_H_INCLUDED
#include <windows.h>
//Cai dat ham gotoXY
void gotoXY(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	_COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
}

#endif // SNAKEGAMEPLAY_H_INCLUDED
