#include "pch.h"
#include "Tetris.h"

enum E_GAMEKEY_TYPE
{
    GAMEKEY_LEFT,
    GAMEKEY_RIGHT,
    GAMEKEY_ROTATE,
    GAMEKEY_DOWN,
    GAMEKEY_SMASH,
	GAMEKEY_HOLD,
};

CTetris::CTetris(void)
    : m_Map()
    , m_Tetrimino()
    , m_Input()
    , m_Output()
{
    m_Map.Clear();
    m_ScoreBoard.Clear();
    m_Tetrimino.Reset(rand() % TETRIMINO_COUNT);
    m_Input.Register(GAMEKEY_LEFT,      VK_LEFT);
    m_Input.Register(GAMEKEY_RIGHT,     VK_RIGHT);
    m_Input.Register(GAMEKEY_ROTATE,    VK_UP);
    m_Input.Register(GAMEKEY_DOWN,      VK_DOWN);
    m_Input.Register(GAMEKEY_SMASH,     VK_SPACE);
    m_Input.Register(GAMEKEY_HOLD,      0x43);
    m_Output.Create(TEXT("BoB TETRIS"), COORD{ 80, 30 }, COORD{ 80, 30});
    bSmash = FALSE;
}

CTetris::~CTetris(void)
{
    m_Output.Destroy();
}

void CTetris::Input(std::list<ST_KEYSTATE>& outState)
{
    m_Input.Query(outState);
}

void CTetris::Update(const std::list<ST_KEYSTATE> stKeyState, int nElapsedTick)
{
    m_Tetrimino.PushState();
    for (ST_KEYSTATE key : stKeyState)
    {
        if (!key.bPressed)
            continue;

        switch (key.nID)
        {
        case GAMEKEY_LEFT:
            m_Tetrimino.MoveSide(-1);
            break;
        case GAMEKEY_RIGHT:
            m_Tetrimino.MoveSide(1);
            break;
        case GAMEKEY_ROTATE:
            m_Tetrimino.PushState();
            m_Tetrimino.Rotate();
            if (m_Map.IsCollide(&m_Tetrimino))
            {
				m_Tetrimino.RestoreState();
                m_Tetrimino.MoveSide(-1);
                m_Tetrimino.Rotate();
                m_Tetrimino.MoveSide(1);
            }
			
            break;
        case GAMEKEY_DOWN:
            this->Falling();
            break;
        case GAMEKEY_SMASH:
            bSmash = TRUE;
            m_Map.MoveBottom(&m_Tetrimino);
            m_Map.Pile(&m_Tetrimino);
            m_Map.RemoveFullLine(&m_ScoreBoard);
            m_Tetrimino.Reset(rand() % TETRIMINO_COUNT);
            if (m_Map.IsCollide(&m_Tetrimino))
            {
                // GameOver
                Sleep(3000);
                m_Map.Clear();
            }
            bHold = FALSE;

            break;
        case GAMEKEY_HOLD:
            //TODO
            if(!m_HoldMap.Empty())
                m_Tetrimino = m_HoldMap.Pop();

			m_HoldMap.Push(&m_Tetrimino);
            bHold = TRUE;
        }
    }

    if (m_Map.IsCollide(&m_Tetrimino))
        m_Tetrimino.RestoreState();
    else
        m_Tetrimino.PopState();
	
    m_Map.PrePile(&m_Tetrimino);
}

void CTetris::Render(void)
{
    m_Output.Clear();
    m_Map.OnDraw(&m_Output);
    m_Tetrimino.OnDraw(&m_Output);
    m_ScoreBoard.OnDraw(&m_Output);
    // THINK : g_nMapWidth와 g_nMapHeight에서 왜 -1을 하고 있었는가?
    m_Output.Flip(SMALL_RECT{ 0, 0, 80, 30}, COORD{ 10, 5 });
    if (bSmash)
    {
        bSmash = FALSE;
        m_Output.Vibrate();
    }
}

void CTetris::Falling()
{
    m_Tetrimino.PushState();
    m_Tetrimino.MoveDown(1);
    if (m_Map.IsCollide(&m_Tetrimino))
    {
        m_Tetrimino.RestoreState();
        m_Map.Pile(&m_Tetrimino);
		m_Map.RemoveFullLine(&m_ScoreBoard);
        m_Tetrimino.Reset(rand() % TETRIMINO_COUNT);
        if (m_Map.IsCollide(&m_Tetrimino))
        {
			//GameOver
            Sleep(3000);
            m_Map.Clear();
        }
        return;
    }
    else
        m_Tetrimino.PopState();
	
}