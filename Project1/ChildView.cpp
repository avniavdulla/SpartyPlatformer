/**
 * \file ChildView.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"
#include "framework.h"

#include <algorithm>
#include "Project1.h"
#include "ChildView.h"
#include "DoubleBufferDC.h"

using namespace Gdiplus;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/// Frame duration in milliseconds
const int FrameDuration = 30;

CChildView::CChildView()
{
	srand((unsigned int)time(nullptr));
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_LEVEL_LEVEL0, &CChildView::OnLevelLevel0)
	ON_COMMAND(ID_LEVEL_LEVEL1, &CChildView::OnLevelLevel1)
	ON_COMMAND(ID_LEVEL_LEVEL2, &CChildView::OnLevelLevel2)
	ON_COMMAND(ID_LEVEL_LEVEL3, &CChildView::OnLevelLevel3)
	ON_WM_ERASEBKGND()
    ON_WM_TIMER()
	ON_WM_KEYDOWN()
    ON_WM_KEYUP()
END_MESSAGE_MAP()



// CChildView message handlers

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

void CChildView::OnPaint() 
{
	CPaintDC paintDC(this); // device context for painting
	CDoubleBufferDC dc(&paintDC); // device context for painting
    Graphics graphics(dc.m_hDC); // Create GDI+ graphics context

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

    /*
     * Compute the elapsed time since the last draw
     */
    LARGE_INTEGER time;
    QueryPerformanceCounter(&time);
    long long diff = time.QuadPart - mLastTime;
    double elapsed = double(diff) / mTimeFreq;
    mLastTime = time.QuadPart;

    mGame.Update(elapsed);
}



/**
 * Handler for Level 0
 */
void CChildView::OnLevelLevel0()
{
	// TODO: Add your command handler code here
}

/**
 * Handler for Level 1
 */
void CChildView::OnLevelLevel1()
{
	// TODO: Add your command handler code here
}

/**
 * Handler for Level 2
 */
void CChildView::OnLevelLevel2()
{
	// TODO: Add your command handler code here
}

/**
 * Handler for Level 3
 */
void CChildView::OnLevelLevel3()
{
	// TODO: Add your command handler code here
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
 */
void CChildView::OnTimer(UINT_PTR nIDEvent)
{
    Invalidate();
    CWnd::OnTimer(nIDEvent);
}


/**
 * Handle key press events
 */
void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    switch (nChar)
    {
    case VK_RIGHT:
        // right arrow pressed
        break;

    case VK_LEFT:
        // left arrow pressed
        break;

    case VK_SPACE:
        // space bar pressed
        break;
    }
}


void CChildView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    switch (nChar)
    {
    case VK_RIGHT:
    case VK_LEFT:
        // left or right arrow released
        break;
    }
}