#pragma once

#include "Map.h"
#include "Tetrimino.h"
#include "KeyInput.h"
#include "ConsoleOutput.h"

class CTetris
{
	CMap m_Map;
	CTetrimino m_Tetrimino;
	CKeyInput m_Input;
	CConsoleOutput m_Output;

public:
	CTetris(void);
	~CTetris(void);

	void Input(std::list<ST_KEYSTATE>& outState);
	void Update(const std::list<ST_KEYSTATE> stKeyState, int nElapsedTick);
	void Render(void);
};

