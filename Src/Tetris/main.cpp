#include "pch.h"
#include "Tetris.h"

DWORD WINAPI FallingCaller(LPVOID pContext)
{
	while (true)
	{
		CTetris& tetris = *(CTetris*)pContext;
		Sleep(300);
		tetris.Falling();
	}

	return 0;
}

int main()
{
	CTetris tetris;

	int nFPS = 120;
	int nSleepTime = 1000 / nFPS;

#ifndef _DEBUG
	HANDLE hHandle = ::CreateThread(nullptr, 0, FallingCaller, (LPVOID)&tetris, 0, nullptr);
	if (hHandle != NULL)
		CloseHandle(hHandle);
#endif

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
