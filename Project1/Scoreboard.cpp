/**
 * \file Scoreboard.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"
#include <string>
#include "Scoreboard.h"

using namespace std;
using namespace Gdiplus;

/**
 * Constructor
 */
CScoreboard::CScoreboard()
{
}

/**
 *  Destructor
 */
CScoreboard::~CScoreboard()
{
}

/**
 * Draw the Scoreboard
 * \param graphics The graphics context to draw on
 * \param scroll The scroll offset
 */
void CScoreboard::Draw(Gdiplus::Graphics* graphics, int scroll)
{
    int min = int(mSeconds / 60);
    int sec = int(mSeconds - (double(min) * 60));
    wstring minString;
    wstring secString;

    minString = to_wstring(min);

    if (sec < 10)
    {
        secString = L"0" + to_wstring(sec);
    }
    else
    {
        secString = to_wstring(sec);
    }

    FontFamily fontFamily(L"Arial");
    Gdiplus::Font font(&fontFamily, 70, FontStyleBold);

    wstring time = minString + L":" + secString;
    wstring score = L"$" + to_wstring(mScore);

    SolidBrush grey(Color(200, 200, 200));

    graphics->DrawString(time.c_str(), -1, &font, PointF(90, 18), &grey);
    graphics->DrawString(score.c_str(), -1, &font, PointF(1050, 18), &grey);
}

/**
 * Handle updates in time of the Scoreboard
 * This is called before we draw and allows us to
 * update our seconds and score
 * \param elapsed Time elapsed since the class call
 */
void CScoreboard::Update(double elapsed)
{
    mSeconds += elapsed;
}

/**
 * Resets the Scoreboard
 */
void CScoreboard::Reset()
{
    mSeconds = 0;
    mScore = 0;
}