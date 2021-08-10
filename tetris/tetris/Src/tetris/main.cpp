#include "stdafx.h"
#include "Tetris.h"

int main()
{
    CTetris tetris;

    int nFramePerSecond = 10;
    int nSleepTimePerFrame = 1000 / nFramePerSecond;
    while (true)
    {
        ST_KEY_STATE stKeyState;
        stKeyState.Clear();

        tetris.Input(&stKeyState);
        tetris.Update(stKeyState);
        tetris.Render();

        Sleep(nSleepTimePerFrame);
    }
    return 0;
}
