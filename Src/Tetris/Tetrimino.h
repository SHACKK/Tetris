#pragma once

#include "RenderObject.h"
#include <stack>

enum E_TETRIMINO_TYPE
{
	TETRIMINO_I = 0,
	TETRIMINO_O,
	TETRIMINO_J,
	TETRIMINO_L,
	TETRIMINO_S,
	TETRIMINO_Z,
	TETRIMINO_T,
	TETRIMINO_COUNT
};

struct ST_TETRIMINO_STATE
{
	int nRotation;
	int nPosX;
	int nPosY;
};

class CTetrimino : public CRenderObject
{
	wchar_t m_szBlock[4][4][4 + 1];
	int m_nRotation;
	std::stack<ST_TETRIMINO_STATE> m_stackState;
	E_TETRIMINO_TYPE m_eType;

public:
	void Reset(int nType);

	void PushState(void);
	void RestoreState(void);
	void PopState(void);

	void MoveSide(int nOffset);
	void MoveDown(int nOffset);
	void Rotate(int nDir = 1);

	int GetPosX();
	int GetPosY();
	wchar_t GetBlock(int nY, int nX);
	E_TETRIMINO_TYPE GetType();

	void OnDraw(CConsoleOutput* pRenderer);
};

