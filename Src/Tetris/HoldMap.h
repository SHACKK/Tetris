#pragma once
#include "RenderObject.h"
#include "Tetrimino.h"

class CHoldMap
{
	CTetrimino m_Tetrimino;
	BOOL m_bExist;
	wchar_t m_szHoldMap[5][5];
	
public:
	CHoldMap();
	~CHoldMap();

	BOOL Empty();
	void Push(CTetrimino* Tetrimino);
	CTetrimino Pop();
};

