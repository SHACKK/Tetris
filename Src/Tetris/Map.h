#pragma once

#include "RenderObject.h"
#include "Tetrimino.h"
#include "ScoreMap.h"

const int g_nBlockWidth = 12;
const int g_nBlockHeight = 18;
const int g_nMapMargin = 2;
const int g_nMapWidth = g_nBlockWidth + g_nMapMargin * 2;
const int g_nMapHeight = g_nBlockHeight + g_nMapMargin;

class CMap : public CRenderObject
{
	wchar_t m_szCurMapData[g_nMapHeight][(g_nMapWidth + 2)];
	wchar_t m_szPreMapData[g_nMapHeight][(g_nMapWidth + 2)];
	int m_nCombo;
public:
	void Clear(void);
	bool IsCollide(CTetrimino* pTetrimino);
	void MoveBottom(CTetrimino* pTetrimino);
	void PrePile(CTetrimino* pTetrimino);
	void Pile(CTetrimino* pTetrimino);
	void RemoveFullLine(CScoreMap* score);
	void OnDraw(CConsoleOutput* pOutput);
};
