/** 
* \file Level.cpp
* \author Avni Avdulla, Hugh Wilson
*/

#include "pch.h"
#include "Level.h"
using namespace std;
using namespace Gdiplus;


/** 
* Constructor for level
* saves the background image into mBackground 
*/
CLevel::CLevel(const wstring& background) {

    //sets the given background image to the level's mBackground based on the given filename
    mBackground = unique_ptr<Bitmap>(Bitmap::FromFile(background.c_str()));
    if (mBackground->GetLastStatus() != Ok)
    {
        AfxMessageBox(L"Failed to open images/background1.png");
    }

    mStart.Set(468, 572);
}

/**
 * Destructor
 */
CLevel::~CLevel()
{
}

/**
 * Add an item to the level
 * \param item New item to add
 */
void CLevel::Add(std::shared_ptr<CItem> item) 
{
    mItems.push_back(item);
}

/**
 * Draw the Level
 * \param graphics The graphics context to draw on
 */
void CLevel::Draw(Gdiplus::Graphics* graphics, int scroll)
{

    for (auto item : mItems)
    {
        item->Draw(graphics, scroll);
    }
}

/**
 * Handle updates for animation
 * \param elapsed The time since the last update
 */
void CLevel::Update(double elapsed)
{
    for (auto item : mItems)
    {
        item->Update(elapsed);
    }
}