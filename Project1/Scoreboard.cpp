/**
 * \file Scoreboard.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"
#include <string>

#include "Scoreboard.h"
#include "Game.h"

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
 * \param height Height of the current window
 * \param width Width of the current window
 */
void CScoreboard::Draw(Gdiplus::Graphics* graphics, int width, int height)
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
    Gdiplus::Font font(&fontFamily, 60, FontStyleBold);

    wstring time = minString + L":" + secString;
    wstring score = L"$" + to_wstring(mScore);
    

    SolidBrush grey(Color(200, 200, 200));
    

    graphics->DrawString(time.c_str(), -1, &font, PointF(60, 18), &grey); 
    graphics->DrawString(score.c_str(), -1, &font, PointF(width - 360, 18), &grey);
}

/**
 * Draw the Scoreboard Splash Text
 * \param graphics The graphics context to draw on
 * \param height Height of the current window
 * \param width Width of the current window
 * \param splashText Text to display
 */
void CScoreboard::DrawSplashText(Gdiplus::Graphics* graphics, int width, int height, wstring splashText) 
{
    FontFamily fontFamily(L"Arial");
    Gdiplus::Font splash(&fontFamily, 100, FontStyleBold);
    SolidBrush pink(Color(255, 105, 180));
    StringFormat stringFormat = new StringFormat();
    stringFormat.SetAlignment(StringAlignmentCenter);

    graphics->DrawString(splashText.c_str(), -1, &splash, PointF(width / 2, height / 2), &stringFormat, &pink);
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