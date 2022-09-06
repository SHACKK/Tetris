#include "pch.h"
#include "Map.h"

void CMap::Clear(void)
{
	m_nPosX = 0;
	m_nPosY = 0;

	for (int y = 0; y < g_nMapHeight; y++)
		wmemset(m_szMapData[y], L'бс', g_nMapWidth);

	for (int y = 0; y < g_nBlockHeight; y++)
		wmemset(m_szMapData[y] + g_nMapMargin, L' ', g_nBlockWidth);
}

bool CMap::IsCollide(CTetrimino* pTetrimino)
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			int nX = pTetrimino->GetPosX();
			int nY = pTetrimino->GetPosY();
			wchar_t cMap = m_szMapData[nY + y][nX + x];
			wchar_t cBlock = pTetrimino->GetBlock(y, x);
			if (cBlock != L' ' && cMap != L' ')
				return true;
		}
	}
	return false;
}

void CMap::Pile(CTetrimino* pTetrimino)
{
	// TODO
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			int nX = pTetrimino->GetPosX();
			int nY = pTetrimino->GetPosY();
			wchar_t cMap = m_szMapData[nY + y][nX + x];;
			wchar_t cBlock = pTetrimino->GetBlock(y, x);
			if (cBlock != L' ' && cMap == L' ')
				m_szMapData[nY + y][nX + x] = cBlock;
		}
	}
	
	for (int y = 0; y < g_nBlockHeight; y++)
	{
		bool bFull = true;
		for (int x = 0; x < g_nBlockWidth; x++)
		{
			if (m_szMapData[y][x + g_nMapMargin] == L' ')
			{
				bFull = false;
				break;
			}
		}
		if (bFull)
		{
			for (int cy = y; cy > 0; cy--)
			{
				wmemcpy(m_szMapData[cy] + g_nMapMargin, m_szMapData[cy - 1] + g_nMapMargin, g_nBlockWidth);
			}
			wmemset(m_szMapData[0] + g_nMapMargin, L' ', g_nBlockWidth);
			y--;
		}
	}
}

void CMap::OnDraw(CConsoleOutput* pRender)
{
	for (int i = 0; i < g_nMapHeight; i++)
		pRender->Print(m_nPosX, m_nPosY + i, m_szMapData[i], g_nMapWidth);
}