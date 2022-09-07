#pragma once

class CConsoleOutput
{
	HANDLE m_hStdOutput;
	HANDLE m_hBackBuffer;
	int m_nBufferWidth;
	int m_nBufferHeight;

	std::vector<CHAR_INFO> m_vecBuffer;

public:
	CConsoleOutput(void);
	~CConsoleOutput(void);

	bool Create(LPCTSTR pszTitle, COORD ScreenSize, COORD WorldSize);
	void Destroy(void);

	void Clear(void);
	void SetColor(int nColor);
	void Print(short x, short y, std::wstring strContext, DWORD dwLen, WORD wColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY, wchar_t cTransparent = L' ');
	void Flip(SMALL_RECT WorldRect, COORD ScreenPos);
	void Vibrate(void);
	// For Color
	HANDLE GetBackBuffer(void) { return m_hBackBuffer; }
};

