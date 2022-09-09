#include "pch.h"
#include "ScoreMap.h"

CScoreMap::CScoreMap()
{
	m_nPosX = 20;
	m_nPosY = 0;
	m_nScore = 0;
}

CScoreMap::~CScoreMap()
{
}

void CScoreMap::Clear(void)
{
	wmemset(m_szBoard[0],0x2550, g_nBoardWidth);
	wmemset(m_szBoard[g_nBoardHeight - 1], 0x2550, g_nBoardWidth);
	
	for (int y = 1; y < g_nBoardHeight - 1; y++)
	{
		wmemset(m_szBoard[y], 0x2551, g_nBoardWidth);
		wmemset(m_szBoard[y] + g_nBoardMargin, L' ', g_nBoardWidth - (g_nBoardMargin * 2));
	}
	wchar_t pszScore[4] = {0, };
	errno_t err = _itow_s(m_nScore, pszScore, 4, 10);
	wmemcpy(m_szBoard[1] + 2, L"SCORE", 5);
	wmemcpy(m_szBoard[3] + 3, pszScore, 4);
}

void CScoreMap::AddScore(int nScore, int nCombo)
{
	m_nScore += 100 * nScore * nCombo;
	if (m_nScore > 9999)
		m_nScore = 9999;
	wchar_t pszScore[5] = {0, };
	errno_t err = _itow_s(m_nScore, pszScore, 5, 10);
	wmemcpy(m_szBoard[3] + 3, pszScore, 4);
}

void CScoreMap::OnDraw(CConsoleOutput* pOutput)
{
	for (int y = 0; y < g_nBoardHeight; y++)
	{
		pOutput->Print(m_nPosX, m_nPosY + y, m_szBoard[y], g_nBoardWidth + 1);
	}
}
