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
    m_Input.Register(GAMEKEY_ROTATE,    VK_SPACE);
    m_Output.Create(TEXT("BoB TETRIS"), COORD{ 100, 30 }, COORD{ g_nMapWidth, g_nMapHeight });
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
            m_Tetrimino.Move(-1);
            break;
        case GAMEKEY_RIGHT:
            m_Tetrimino.Move(1);
            break;
        case GAMEKEY_ROTATE:
            m_Tetrimino.Rotate();
            break;
        case GAMEKEY_DOWN:
            m_Tetrimino.Move(-1);
            break;
        case GAMEKEY_SMASH:
            // [TODO]
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
    m_Output.Flip(SMALL_RECT{ 0, 0, g_nMapWidth - 1, g_nMapHeight - 1 }, COORD{ 40, 5 });
}