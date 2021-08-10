#pragma once

#include "stdafx.h"
#include "Tetrimino.h"
#include "Map.h"

struct ST_KEY_STATE
{
	bool bRotateKeyDown;
	bool bLeftKeyDown;
	bool bRightKeyDown;

	void Clear(void)
	{
		bRotateKeyDown = false;
		bLeftKeyDown = false;
		bRightKeyDown = false;
	}
};

class CTetris
{
	CMap m_Map;
	CTetrimino m_Tetrimino;
	CRenderer m_Render;

public:
	CTetris(void);
	~CTetris(void);
	
	void Input(ST_KEY_STATE* pKeyState);
	void Update(ST_KEY_STATE stKeyState);
	void Render(void);
};


