#include <iostream>
#include <conio.h>
#include "Sound.h"
#include "EndScreen.h"
#include "setConsole.h"
using namespace std;


void EndScreen(int x)
{
    ShowConsoleCursor(false);

    gotoxy(10,10);
    cout << "  /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$        /$$$$$$  /$$    /$$ /$$$$$$$$ /$$$$$$$ \n";
    gotoxy(10,11);
    cout << " /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/       /$$__  $$| $$   | $$| $$_____/| $$__  $$\n";
    gotoxy(10,12);
    cout << "| $$  \\__/| $$  \\ $$| $$$$  /$$$$| $$            | $$  \\ $$| $$   | $$| $$      | $$  \\ $$\n";
    gotoxy(10,13);
    cout << "| $$ /$$$$| $$$$$$$$| $$ $$/$$ $$| $$$$$         | $$  | $$|  $$ / $$/| $$$$$   | $$$$$$$/\n";
    gotoxy(10,14);
    cout << "| $$|_  $$| $$__  $$| $$  $$$| $$| $$__/         | $$  | $$ \\  $$ $$/ | $$__/   | $$__  $$\n";
    gotoxy(10,15);
    cout << "| $$  \\ $$| $$  | $$| $$\\  $ | $$| $$            | $$  | $$  \\  $$$/  | $$      | $$  \\ $$\n";
    gotoxy(10,16);
    cout << "|  $$$$$$/| $$  | $$| $$ \\/  | $$| $$$$$$$$      |  $$$$$$/   \\  $/   | $$$$$$$$| $$  | $$\n";
    gotoxy(10,17);
    cout << " \\______/ |__/  |__/|__/     |__/|________/       \\______/     \\_/    |________/|__/  |__/\n";
    gotoxy(10,18);
    cout << "                                                                                          \n";
    gotoxy(10,19);
    cout << "                                                                                          \n";
    gotoxy(10,20);
    cout << "                                                                                          ";
    gotoxy(50,21);
    cout<<"Your Score: "<<x;
    playSound("b.wav",0);
    while(kbhit()!=1)
    {

    }

}

