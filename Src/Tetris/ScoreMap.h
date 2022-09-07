#pragma once
#include "RenderObject.h"

#define BASE_SCORE 100

const int g_nBoardWidth = 9;
const int g_nBoardHeight = 5;
const int g_nBoardMargin = 1;

class CScoreMap : public CRenderObject
{
	int m_nScore;
	wchar_t m_szBoard[g_nBoardHeight][g_nBoardWidth + 1];
	
public:
	CScoreMap();
	~CScoreMap();

	void Clear(void);
	void AddScore(int nScore, int nCombo);
	void OnDraw(CConsoleOutput* pOutput);
};