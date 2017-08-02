#include <iostream>
#include <conio.h>
#include "menuStart.h"
#include "setConsole.h"


using namespace std;


void menuStart()
{
    ShowConsoleCursor(false);

    gotoxy(30,10);
    cout << " ____  __ _   __   __ _  ____     ___   __   _  _  ____ \n";
    gotoxy(30,11);
    cout << "/ ___)(  ( \\ / _\\ (  / )(  __)   / __) / _\\ ( \\/ )(  __)\n";
    gotoxy(30,12);
    cout << "\\___ \\/    //    \\ )  (  ) _)   ( (_ \\/    \\/ \\/ \\ ) _) \n";
    gotoxy(30,13);
    cout << "(____/\\_)__)\\_/\\_/(__\\_)(____)   \\___/\\_/\\_/\\_)(_/(____)";

    gotoxy(45,17);
    cout<<"PRESS ANY BUTTON TO PLAY";



    while(kbhit()!=1)
    {

    }
}

