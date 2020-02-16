/**
 * \file ChildView.h
 *
 * \author Sean Nguyen
 *
 * Class that implements the child window our program draws in.
 *
 * The window is a child of the main frame, which holds this
 * window, the menu bar, and the status bar.
 */

#pragma once

#include "Game.h"

/**
 * The child window our program draws in.
 */
class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()

private:
    /// An object that describes the Game
    CGame mGame;

    /// True until the first time we draw
    bool mFirstDraw = true;

    /// Last time we read the timer
    long long mLastTime;

    /// Rate the timer updates
    double mTimeFreq;

public:
	afx_msg void OnLevelLevel0();
	afx_msg void OnLevelLevel1();
	afx_msg void OnLevelLevel2();
	afx_msg void OnLevelLevel3();
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg void OnTimer(UINT_PTR nIDEvent);
};

