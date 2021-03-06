/**
 * \file ChildView.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"
#include "framework.h"

#include <string>
#include <algorithm>
#include "Project1.h"
#include "ChildView.h"
#include "DoubleBufferDC.h"

using namespace std;
using namespace Gdiplus;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/// Frame duration in milliseconds
const int FrameDuration = 30;

/**
 * Constructor
 */
CChildView::CChildView()
{
    srand((unsigned int)time(nullptr));
}

/**
 * Destructor
 */
CChildView::~CChildView()
{
}

BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
    ON_WM_ERASEBKGND()
    ON_WM_TIMER()
    ON_WM_KEYDOWN()
    ON_WM_KEYUP()
    ON_COMMAND(ID_LEVEL_LEVEL0, &CChildView::OnLevelLevel0)
    ON_COMMAND(ID_LEVEL_LEVEL1, &CChildView::OnLevelLevel1)
    ON_COMMAND(ID_LEVEL_LEVEL2, &CChildView::OnLevelLevel2)
    ON_COMMAND(ID_LEVEL_LEVEL3, &CChildView::OnLevelLevel3)
END_MESSAGE_MAP()

/** 
 * This function is called before the window is created.
 * \param cs A structure with the window creation parameters
 * \returns TRUE
 */
BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

/** 
 * This function is called to draw in the window.
 *
 * This function is called in response to a drawing message
 * whenever we need to redraw the window on the screen.
 * It is responsible for painting the window.
 * \return Void
 */
void CChildView::OnPaint() 
{
    CPaintDC paintDC(this); // device context for painting
    CDoubleBufferDC dc(&paintDC);
    Graphics graphics(dc.m_hDC); // Create GDI+ graphics context
    graphics.Clear(Color(0, 0, 0));

    CRect rect;
    GetClientRect(&rect);

    mGame.OnDraw(&graphics, rect.Width(), rect.Height());

    if (mFirstDraw)
    {
        mFirstDraw = false;
        SetTimer(1, FrameDuration, nullptr);

        /*
         * Initialize the elapsed time system
         */
        LARGE_INTEGER time, freq;
        QueryPerformanceCounter(&time);
        QueryPerformanceFrequency(&freq);

        mLastTime = time.QuadPart;
        mTimeFreq = double(freq.QuadPart);
    }

    // Compute the elapsed time since the last draw
    LARGE_INTEGER time;
    QueryPerformanceCounter(&time);
    long long diff = time.QuadPart - mLastTime;
    double elapsed = double(diff) / mTimeFreq;
    mLastTime = time.QuadPart;

    /// Maximum amount of time to allow for elapsed
    const double MaxElapsed = 0.050;
    //
    // Prevent tunnelling
    //
    while (elapsed > MaxElapsed)
    {
        mGame.Update(MaxElapsed);

        elapsed -= MaxElapsed;
    }

    // Consume any remaining time
    if (elapsed > 0)
    {
        mGame.Update(elapsed);
    }
    
}

/**
 * Erase the background
 *
 * This is disabled to eliminate flicker
 * \param pDC Device context
 * \returns FALSE
 */
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
    return FALSE;
}

/**
 * Handle timer events
 * \param nIDEvent The timer event ID
 * \return Void
 */
void CChildView::OnTimer(UINT_PTR nIDEvent)
{
    Invalidate();
    CWnd::OnTimer(nIDEvent);
}

/**
 * Handle key presses for player-controlled Gnome
 * \param nChar Key pressed down
 * \param nRepCnt Count of key pressed down
 * \param nFlags Flags for keys pressed down
 * \return Void
 */
void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    switch (nChar)
    {
    case VK_RIGHT:
        mGame.GetGnome()->GoRight(true);
        break;
    case VK_LEFT:
        mGame.GetGnome()->GoLeft(true);
        break;
    case VK_SPACE:
        mGame.GetGnome()->Jump();
        break;
    }
}

/**
 * Handle key up events
 * \param nChar Key up
 * \param nRepCnt Count of key up
 * \param nFlags Flags for key up
 * \return Void
 */
void CChildView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    switch (nChar)
    {
    case VK_RIGHT:
        mGame.GetGnome()->GoRight(false);
        break;
    case VK_LEFT:
        mGame.GetGnome()->GoLeft(false);
        break;

    }
}

/**
 * Handler for Level 0
 * \return Void
 */
void CChildView::OnLevelLevel0()
{
    mGame.Load(0);
    Invalidate();
}

/**
 * Handler for Level 1
 * \return Void
 */
void CChildView::OnLevelLevel1()
{
    mGame.Load(1);
    Invalidate();
}

/**
 * Handler for Level 2
 * \return Void
 */
void CChildView::OnLevelLevel2()
{
    mGame.Load(2);
    Invalidate();
}

/**
 * Handler for Level 3
 * \return Void
 */
void CChildView::OnLevelLevel3()
{
    mGame.Load(3);
    Invalidate();
}
