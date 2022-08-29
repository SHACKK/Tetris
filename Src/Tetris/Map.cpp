#include "pch.h"
#include "Map.h"

void CMap::Clear(void)
{
	m_nPosX = 0;
	m_nPosY = 0;

	for (int y = 0; y < g_nMapHeight; y++)
		memset(m_szMapData[y], '*', g_nMapWidth);

	for (int y = 0; y < g_nBlockHeight; y++)
		memset(m_szMapData[y] + g_nMapMargin, ' ', g_nBlockWidth);
}

bool CMap::IsCollide(CTetrimino* pTetrimino)
{
	return false;
}

void CMap::Pile(CTetrimino* pTetrimino)
{
	// TODO
}

void CMap::OnDraw(CConsoleOutput* pRender)
{
	for (int i = 0; i < g_nMapHeight; i++)
		pRender->Print(m_nPosX, m_nPosY + i, m_szMapData[i], g_nMapWidth);
}