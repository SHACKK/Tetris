#include "pch.h"
#include "Map.h"

void CMap::Clear(void)
{
	m_nPosX = 0;
	m_nPosY = 0;
	m_nCombo = 0;
	
	for (int y = 0; y < g_nMapHeight; y++)
		wmemset(m_szCurMapData[y], L'бс', g_nMapWidth);

	for (int y = 0; y < g_nBlockHeight; y++)
		wmemset(m_szCurMapData[y] + g_nMapMargin, L' ', g_nBlockWidth);
	
	for (int y = 0; y < g_nMapHeight; y++)
		wmemset(m_szPreMapData[y], L'бс', g_nMapWidth);
	
	for (int y = 0; y < g_nBlockHeight; y++)
		wmemset(m_szPreMapData[y] + g_nMapMargin, L' ', g_nBlockWidth);
}

bool CMap::IsCollide(CTetrimino* pTetrimino)
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			int nX = pTetrimino->GetPosX();
			int nY = pTetrimino->GetPosY();
			wchar_t cMap = m_szCurMapData[nY + y][nX + x];
			wchar_t cBlock = pTetrimino->GetBlock(y, x);
			if (cBlock != L' ' && cMap != L' ')
				return true;
		}
	}
	return false;
}

void CMap::MoveBottom(CTetrimino* pTetrimino)
{
	do
	{
		pTetrimino->PopState();
		pTetrimino->PushState();
		pTetrimino->MoveDown(1);
	} while (!(this->IsCollide(pTetrimino)));

	pTetrimino->RestoreState();
}

void CMap::PrePile(CTetrimino* pTetrimino)
{
	CTetrimino PreTetrimino = *pTetrimino;
	this->MoveBottom(&PreTetrimino);
	
	for (int i = 0; i < g_nMapHeight; i++)
	{
		wmemcpy(m_szPreMapData[i], m_szCurMapData[i], g_nMapWidth);
	}
	
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			int nX = PreTetrimino.GetPosX();
			int nY = PreTetrimino.GetPosY();
			wchar_t cBlock = PreTetrimino.GetBlock(y, x);
			if (cBlock != L' ')
				m_szPreMapData[nY + y][nX + x] = L'бр';
		}
	}
}

void CMap::Pile(CTetrimino* pTetrimino)
{
	// TODO
	/*for (int i = 0; i < g_nMapHeight; i++)
		wmemcpy(m_szCurMapData[i], m_szPreMapData[i], g_nMapWidth);*/
	
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			int nX = pTetrimino->GetPosX();
			int nY = pTetrimino->GetPosY();
			wchar_t szBlock = pTetrimino->GetBlock(y, x);
			if (szBlock != L' ')
				m_szCurMapData[nY + y][nX + x] = szBlock;
		}
	}
}

void CMap::RemoveFullLine(CScoreMap* score)
{
	int nLine = 0;
	
	for (int y = 0; y < g_nBlockHeight; y++)
	{
		bool bFull = true;
		for (int x = 0; x < g_nBlockWidth; x++)
		{
			if (m_szCurMapData[y][x + g_nMapMargin] == L' ')
			{
				bFull = false;
				break;
			}
		}
		if (bFull)
		{
			nLine++;
			for (int cy = y; cy > 0; cy--)
			{
				wmemcpy(m_szCurMapData[cy] + g_nMapMargin, m_szCurMapData[cy - 1] + g_nMapMargin, g_nBlockWidth);
			}
			wmemset(m_szCurMapData[0] + g_nMapMargin, L' ', g_nBlockWidth);
			y--;
		}
	}

	for (int y = 0; y < g_nBlockHeight; y++)
		wmemset(m_szPreMapData[y] + g_nMapMargin, L' ', g_nBlockWidth);

	if (nLine != 0)
		m_nCombo++;
	else
		m_nCombo = 0;
	
	score->AddScore(nLine, m_nCombo);
}

void CMap::OnDraw(CConsoleOutput* pRender)
{
	for (int i = 0; i < g_nMapHeight; i++)
		pRender->Print(m_nPosX, m_nPosY + i, m_szPreMapData[i], g_nMapWidth);
}