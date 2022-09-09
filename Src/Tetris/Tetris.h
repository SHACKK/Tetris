#pragma once

#include "Map.h"
#include "ScoreMap.h"
#include "HoldMap.h"
#include "NextTetriminoMap.h"
#include "Tetrimino.h"
#include "KeyInput.h"
#include "ConsoleOutput.h"

class CTetris
{
	CMap m_Map;
	CScoreMap m_ScoreBoard;
	CHoldMap m_HoldMap;
	CNextTetriminoMap m_NextTetriminoMap;
	CTetrimino m_Tetrimino;
	CKeyInput m_Input;
	CConsoleOutput m_Output;
	
	BOOL bSmash;
	BOOL bHold;
public:
	CTetris(void);
	~CTetris(void);

	void Input(std::list<ST_KEYSTATE>& outState);
	void Update(const std::list<ST_KEYSTATE> stKeyState, int nElapsedTick);
	void Render(void);
	void Falling();
};
