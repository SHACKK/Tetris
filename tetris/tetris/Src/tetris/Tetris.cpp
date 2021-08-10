#include "Tetris.h"
#include "stdafx.h"

CTetris::CTetris(void) {

	m_Tetrimino.Reset(rand() % TETRIMINO_COUNT);
	m_Map.Clear();
}
CTetris::~CTetris(void) {

}

void CTetris::Input(ST_KEY_STATE* pKeyState) {

	char eKeyDown = 0;
	while (_kbhit())
		eKeyDown = _getch();

	if ('A' == eKeyDown || 'a' == eKeyDown)
		pKeyState->bLeftKeyDown = true;
	if ('D' == eKeyDown || 'd' == eKeyDown)
		pKeyState->bRightKeyDown = true;
	if ('W' == eKeyDown || 'w' == eKeyDown)
		pKeyState->bRotateKeyDown = true;
}

void CTetris::Update(ST_KEY_STATE stKeyState) {
	// todo
}

void CTetris::Render(void) {

	m_Render.Clear();
	m_Map.OnDraw(&m_Render);
	m_Tetrimino.OnDraw(&m_Render);
	m_Render.Render();

}