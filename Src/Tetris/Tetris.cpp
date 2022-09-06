#include "pch.h"
#include "Tetris.h"

enum E_GAMEKEY_TYPE
{
    GAMEKEY_LEFT,
    GAMEKEY_RIGHT,
    GAMEKEY_ROTATE,
    GAMEKEY_DOWN,
    GAMEKEY_SMASH,
};

CTetris::CTetris(void)
    : m_Map()
    , m_Tetrimino()
    , m_Input()
    , m_Output()
{
    m_Map.Clear();
    m_Tetrimino.Reset(rand() % TETRIMINO_COUNT);
    m_Input.Register(GAMEKEY_LEFT,      VK_LEFT);
    m_Input.Register(GAMEKEY_RIGHT,     VK_RIGHT);
    m_Input.Register(GAMEKEY_ROTATE,        VK_UP);
    m_Input.Register(GAMEKEY_DOWN,      VK_DOWN);
    m_Input.Register(GAMEKEY_SMASH,    VK_SPACE);
    m_Output.Create(TEXT("BoB TETRIS"), COORD{ 120, 30 }, COORD{ g_nMapWidth * 2, (g_nMapHeight + 1) * 2 });
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
            m_Tetrimino.Rotate();
            break;
        case GAMEKEY_DOWN:
            this->Falling();
            break;
        case GAMEKEY_SMASH:
            do
            {
                m_Tetrimino.PopState();
                m_Tetrimino.PushState();
                m_Tetrimino.MoveDown(1);
            } while (!m_Map.IsCollide(&m_Tetrimino));

            m_Tetrimino.RestoreState();

            m_Map.Pile(&m_Tetrimino);
            m_Tetrimino.Reset(rand() % TETRIMINO_COUNT);
            if (m_Map.IsCollide(&m_Tetrimino))
            {
                // GameOver
                Sleep(3000);
                m_Map.Clear();
            }
            break;
        }
    }

    if (m_Map.IsCollide(&m_Tetrimino))
        m_Tetrimino.RestoreState();
    else
        m_Tetrimino.PopState();
}

void CTetris::Render(void)
{
    m_Output.Clear();
    m_Map.OnDraw(&m_Output);
    m_Tetrimino.OnDraw(&m_Output);
    m_Output.Flip(SMALL_RECT{ 0, 0, (g_nMapWidth - 1) * 2, (g_nMapHeight - 1) * 2 }, COORD{ 40, 5 });
}

void CTetris::Falling()
{
    m_Tetrimino.PushState();
    m_Tetrimino.MoveDown(1);
    if (m_Map.IsCollide(&m_Tetrimino))
    {
        m_Tetrimino.RestoreState();
        m_Map.Pile(&m_Tetrimino);
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