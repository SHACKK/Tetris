#include "pch.h"
#include "Tetris.h"

int main()
{
	CTetris tetris;

	int nFPS = 120;
	int nSleepTime = 1000 / nFPS;
	while (true)
	{
		std::list<ST_KEYSTATE> keyState;

		tetris.Input(keyState);
		tetris.Update(keyState, nSleepTime);
		tetris.Render();

		Sleep(nSleepTime);
	}
	return 0;
}
