#include "pch.h"
#include "HoldMap.h"

CHoldMap::CHoldMap()
{
	m_bExist = FALSE;
}

CHoldMap::~CHoldMap()
{
}

BOOL CHoldMap::Empty()
{
	return m_bExist;
}

void CHoldMap::Push(CTetrimino* Tetrimino)
{
	m_bExist = TRUE;
	m_Tetrimino = *Tetrimino;
}

CTetrimino CHoldMap::Pop()
{
	m_bExist = FALSE;
	return m_Tetrimino;
}
