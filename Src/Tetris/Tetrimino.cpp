#include "pch.h"
#include "Tetrimino.h"

void CTetrimino::Reset(int nType)
{
	m_nPosX = 5;
	m_nPosY = 0;
	m_nRotation = 0;
	switch (nType)
	{
	case TETRIMINO_I:
		wmemcpy(m_szBlock[0][0], L"бс   ", 5);
		wmemcpy(m_szBlock[0][1], L"бс   ", 5);
		wmemcpy(m_szBlock[0][2], L"бс   ", 5);
		wmemcpy(m_szBlock[0][3], L"бс   ", 5);
		
		wmemcpy(m_szBlock[1][0], L"бсбсбсбс", 5);
		wmemcpy(m_szBlock[1][1], L"    ", 5);
		wmemcpy(m_szBlock[1][2], L"    ", 5);
		memcpy(m_szBlock[1][3], L"    ", 5);

		wmemcpy(m_szBlock[2][0], L"бс   ", 5);
		wmemcpy(m_szBlock[2][1], L"бс   ", 5);
		wmemcpy(m_szBlock[2][2], L"бс   ", 5);
		wmemcpy(m_szBlock[2][3], L"бс   ", 5);

		wmemcpy(m_szBlock[3][0], L"бсбсбсбс", 5);
		wmemcpy(m_szBlock[3][1], L"    ", 5);
		wmemcpy(m_szBlock[3][2], L"    ", 5);
		wmemcpy(m_szBlock[3][3], L"    ", 5);

		m_eType = TETRIMINO_I;
		break;

	case TETRIMINO_O:
		wmemcpy(m_szBlock[0][0], L"бсбс  ", 5);
		wmemcpy(m_szBlock[0][1], L"бсбс  ", 5);
		wmemcpy(m_szBlock[0][2], L"    ", 5);
		wmemcpy(m_szBlock[0][3], L"    ", 5);
		
		wmemcpy(m_szBlock[1][0], L"бсбс  ", 5);
		wmemcpy(m_szBlock[1][1], L"бсбс  ", 5);
		wmemcpy(m_szBlock[1][2], L"    ", 5);
		wmemcpy(m_szBlock[1][3], L"    ", 5);
		
		wmemcpy(m_szBlock[2][0], L"бсбс  ", 5);
		wmemcpy(m_szBlock[2][1], L"бсбс  ", 5);
		wmemcpy(m_szBlock[2][2], L"    ", 5);
		wmemcpy(m_szBlock[2][3], L"    ", 5);
		
		wmemcpy(m_szBlock[3][0], L"бсбс  ", 5);
		wmemcpy(m_szBlock[3][1], L"бсбс  ", 5);
		wmemcpy(m_szBlock[3][2], L"    ", 5);
		wmemcpy(m_szBlock[3][3], L"    ", 5);

		m_eType = TETRIMINO_O;
		break;

	case TETRIMINO_J:
		wmemcpy(m_szBlock[0][0], L"бсбсбс ", 5);
		wmemcpy(m_szBlock[0][1], L"  бс ", 5);
		wmemcpy(m_szBlock[0][2], L"    ", 5);
		wmemcpy(m_szBlock[0][3], L"    ", 5);
		
		wmemcpy(m_szBlock[1][0], L"бсбс  ", 5);
		wmemcpy(m_szBlock[1][1], L"бс   ", 5);
		wmemcpy(m_szBlock[1][2], L"бс   ", 5);
		wmemcpy(m_szBlock[1][3], L"    ", 5);
		
		wmemcpy(m_szBlock[2][0], L"бс   ", 5);
		wmemcpy(m_szBlock[2][1], L"бсбсбс ", 5);
		wmemcpy(m_szBlock[2][2], L"    ", 5);
		wmemcpy(m_szBlock[2][3], L"    ", 5);
		
		wmemcpy(m_szBlock[3][0], L" бс  ", 5);
		wmemcpy(m_szBlock[3][1], L" бс  ", 5);
		wmemcpy(m_szBlock[3][2], L"бсбс  ", 5);
		wmemcpy(m_szBlock[3][3], L"    ", 5);

		m_eType = TETRIMINO_J;
		break;

	case TETRIMINO_L:
		wmemcpy(m_szBlock[0][0], L"бс   ", 5);
		wmemcpy(m_szBlock[0][1], L"бсбсбс ", 5);
		wmemcpy(m_szBlock[0][2], L"    ", 5);
		wmemcpy(m_szBlock[0][3], L"    ", 5);
		
		wmemcpy(m_szBlock[1][0], L" бс  ", 5);
		wmemcpy(m_szBlock[1][1], L" бс  ", 5);
		wmemcpy(m_szBlock[1][2], L"бсбс  ", 5);
		wmemcpy(m_szBlock[1][3], L"    ", 5);
		
		wmemcpy(m_szBlock[2][0], L"бсбсбс ", 5);
		wmemcpy(m_szBlock[2][1], L"  бс ", 5);
		wmemcpy(m_szBlock[2][2], L"    ", 5);
		wmemcpy(m_szBlock[2][3], L"    ", 5);
		
		wmemcpy(m_szBlock[3][0], L"бсбс  ", 5);
		wmemcpy(m_szBlock[3][1], L"бс   ", 5);
		wmemcpy(m_szBlock[3][2], L"бс   ", 5);
		wmemcpy(m_szBlock[3][3], L"    ", 5);

		m_eType = TETRIMINO_L;
		break;

	case TETRIMINO_S:
		wmemcpy(m_szBlock[0][0], L" бсбс ", 5);
		wmemcpy(m_szBlock[0][1], L"бсбс  ", 5);
		wmemcpy(m_szBlock[0][2], L"    ", 5);
		wmemcpy(m_szBlock[0][3], L"    ", 5);
		
		wmemcpy(m_szBlock[1][0], L"бс   ", 5);
		wmemcpy(m_szBlock[1][1], L"бсбс  ", 5);
		wmemcpy(m_szBlock[1][2], L" бс  ", 5);
		wmemcpy(m_szBlock[1][3], L"    ", 5);
		
		wmemcpy(m_szBlock[2][0], L" бсбс ", 5);
		wmemcpy(m_szBlock[2][1], L"бсбс  ", 5);
		wmemcpy(m_szBlock[2][2], L"    ", 5);
		wmemcpy(m_szBlock[2][3], L"    ", 5);
		
		wmemcpy(m_szBlock[3][0], L"бс   ", 5);
		wmemcpy(m_szBlock[3][1], L"бсбс  ", 5);
		wmemcpy(m_szBlock[3][2], L" бс  ", 5);
		wmemcpy(m_szBlock[3][3], L"    ", 5);

		m_eType = TETRIMINO_S;
		break;

	case TETRIMINO_Z:
		wmemcpy(m_szBlock[0][0], L"бсбс  ", 5);
		wmemcpy(m_szBlock[0][1], L" бсбс ", 5);
		wmemcpy(m_szBlock[0][2], L"    ", 5);
		wmemcpy(m_szBlock[0][3], L"    ", 5);
		
		wmemcpy(m_szBlock[1][0], L" бс  ", 5);
		wmemcpy(m_szBlock[1][1], L"бсбс  ", 5);
		wmemcpy(m_szBlock[1][2], L"бс   ", 5);
		wmemcpy(m_szBlock[1][3], L"    ", 5);
		
		wmemcpy(m_szBlock[2][0], L"бсбс  ", 5);
		wmemcpy(m_szBlock[2][1], L" бсбс ", 5);
		wmemcpy(m_szBlock[2][2], L"    ", 5);
		wmemcpy(m_szBlock[2][3], L"    ", 5);
		
		wmemcpy(m_szBlock[3][0], L" бс  ", 5);
		wmemcpy(m_szBlock[3][1], L"бсбс  ", 5);
		wmemcpy(m_szBlock[3][2], L"бс   ", 5);
		wmemcpy(m_szBlock[3][3], L"    ", 5);

		m_eType = TETRIMINO_Z;
		break;

	case TETRIMINO_T:
		wmemcpy(m_szBlock[0][0], L" бс  ", 5);
		wmemcpy(m_szBlock[0][1], L"бсбсбс ", 5);
		wmemcpy(m_szBlock[0][2], L"    ", 5);
		wmemcpy(m_szBlock[0][3], L"    ", 5);

		wmemcpy(m_szBlock[1][0], L" бс  ", 5);
		wmemcpy(m_szBlock[1][1], L"бсбс  ", 5);
		wmemcpy(m_szBlock[1][2], L" бс  ", 5);
		wmemcpy(m_szBlock[1][3], L"    ", 5);

		wmemcpy(m_szBlock[2][0], L"бсбсбс ", 5);
		wmemcpy(m_szBlock[2][1], L" бс  ", 5);
		wmemcpy(m_szBlock[2][2], L"    ", 5);
		wmemcpy(m_szBlock[2][3], L"    ", 5);

		wmemcpy(m_szBlock[3][0], L"бс   ", 5);
		wmemcpy(m_szBlock[3][1], L"бсбс  ", 5);
		wmemcpy(m_szBlock[3][2], L"бс   ", 5);
		wmemcpy(m_szBlock[3][3], L"    ", 5);

		m_eType = TETRIMINO_T;
		break;
	}
}

void CTetrimino::PushState(void)
{
	ST_TETRIMINO_STATE state;
	state.nPosX = m_nPosX;
	state.nPosY = m_nPosY;
	state.nRotation = m_nRotation;
	m_stackState.push(state);
}

void CTetrimino::RestoreState(void)
{
	if (m_stackState.empty())
		return;

	m_nPosX = m_stackState.top().nPosX;
	m_nPosY = m_stackState.top().nPosY;
	m_nRotation = m_stackState.top().nRotation;
	m_stackState.pop();
}

void CTetrimino::PopState(void)
{
	if (m_stackState.empty())
		return;

	m_stackState.pop();
}

void CTetrimino::MoveSide(int nOffset)
{
	m_nPosX += nOffset;
}

void CTetrimino::MoveDown(int nOffset)
{
	m_nPosY += nOffset;
}

void CTetrimino::Rotate(int nDir)
{
	m_nRotation = (m_nRotation + nDir) % 4;
}

int CTetrimino::GetPosX()
{
	return m_nPosX;
}

int CTetrimino::GetPosY()
{
	return m_nPosY;
}

wchar_t CTetrimino::GetBlock(int nY, int nX)
{
	return m_szBlock[m_nRotation][nY][nX];
}

E_TETRIMINO_TYPE CTetrimino::GetType()
{
	return m_eType;
}

void CTetrimino::OnDraw(CConsoleOutput* pRenderer)
{
	pRenderer->Print(m_nPosX, m_nPosY + 0, m_szBlock[m_nRotation][0], 4, ' ');
	pRenderer->Print(m_nPosX, m_nPosY + 1, m_szBlock[m_nRotation][1], 4, ' ');
	pRenderer->Print(m_nPosX, m_nPosY + 2, m_szBlock[m_nRotation][2], 4, ' ');
	pRenderer->Print(m_nPosX, m_nPosY + 3, m_szBlock[m_nRotation][3], 4, ' ');
}