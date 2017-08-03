#include "Sound.h"
#include <windows.h> //included mmsystem.h

using namespace std;

void playSound(char* dir, bool repeat)
{
    if (repeat)
        PlaySound(TEXT(dir), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
    else
        PlaySound(TEXT(dir), NULL, SND_FILENAME | SND_ASYNC);
}

void stopSound()
{
    PlaySound(NULL, 0, 0);
}
