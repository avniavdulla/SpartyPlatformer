/**
 * \file Game.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"

#include "Game.h"
#include "Background.h"
#include "Obstacle.h"
#include "Platform.h"
#include "Villain.h"

using namespace std;
using namespace Gdiplus;
using namespace xmlnode;

/// Game area height in virtual pixels
const static int Height = 1024;

/**
 * Constructor
 */
CGame::CGame()
{
    mGnome = make_shared<CGnome>(this);
}

/**
 * Draw the Game
 * \param graphics The GDI+ graphics context to draw on
 * \param width Width of the client window
 * \param height Height of the client window
 */
void CGame::OnDraw(Gdiplus::Graphics* graphics, int width, int height)
{

    //
    // Automatic Scaling
    //
    mScale = float(height) / float(Height);
    graphics->ScaleTransform(mScale, mScale);

    // Determine the virtual width
    auto virtualWidth = (float)width / mScale;

    // Compute the amount to scroll in the X dimension
    auto scroll = (float)-mGnome->GetX() + virtualWidth / 2.0f;
    // auto scroll = 0;

    for (auto item : mItems)
    {
        item->Draw(graphics, scroll);
    }

    mGnome->Draw(graphics, scroll);
    mScoreboard.Draw(graphics, virtualWidth, (float)height / mScale);

    if (mInitial)
    {
        wstring splashText = L"Level " + to_wstring(mLevel.GetLevelNum()) + L" Begin";
        mScoreboard.DrawSplashText(graphics, virtualWidth, (float)height / mScale, splashText);
    }

    if (mLose)
    {
        wstring splashText = L"You Lose!";
        mScoreboard.DrawSplashText(graphics, virtualWidth, (float)height / mScale, splashText);
    }
}

/**
 * Handle updates for animation
 * \param elapsed The time since the last update
 */
void CGame::Update(double elapsed)
{
    if (mInitial)
    {
        mElapsed += elapsed;

        if (mElapsed >= 1)
        {
            mElapsed = 0;
            mInitial = false;
            mGnome->SetImmobile(false);
        }
    }

    if (mLose)
    {
        mElapsed += elapsed;

        if (mElapsed >= 2)
        {
            mElapsed = 0;
            mGnome->SetImmobile(false);
            Clear();
            mLevel.Reset();
            mScoreboard.Reset();
            mGnome->SetReset(true);
            mLevel.Install(this);
            mGnome->SetLocation(mStart);
            mInitial = true;
            mLose = false;
        }
    }

    for (auto item : mItems)
    {
        item->Update(elapsed);
    }

    for (auto item : mDelete)
    {
        auto deleteItem = find(mItems.begin(), mItems.end(), item);

        if (deleteItem != mItems.end())
        {
            mItems.erase(deleteItem);
        }
    }

    mGnome->Update(elapsed);
    mScoreboard.Update(elapsed);
}

/**
 * Add an Item to the Game
 * \param item New Item to add
 */
void CGame::Add(std::shared_ptr<CItem> item)
{
    mItems.push_back(item);
}

/**
 * Clear the Game
 */
void CGame::Clear()
{
    mItems.clear();
    mDelete.clear();
}

/**
 * Load the Game from a specified Level
 * \param levelNum Level number of Level to load
 */
void CGame::Load(int levelNum)
{
    Clear();
    mLevel.SetLevel(levelNum);
    mLevel.Install(this);
    mScoreboard.Reset();
    mStart = mLevel.GetStart();
    mGnome->SetImmobile(true);
    mInitial = true;
}

/**
 * Loads the next Level based on the current Level
 */
void CGame::NextLevel()
{   
    mScoreboard.Reset();
    mLevel.Reset();
    mLoading = true;
    int levelNum = mLevel.GetLevelNum();
    if (levelNum < 3) { 
        Load(levelNum + 1);
    }   
    else 
    { 
        Load(3); 
    }
    mGnome->SetReset(true);
    mInitial = true;
}

/**
 * Detect collisions within the Game
 * \param gnome The player-controlled Gnome
 * \return Item that is colliding with the Gnome
 */
shared_ptr<CItem> CGame::CollisionTest(CGnome* gnome)
{
    for (auto item : mItems)
    {   
        if (item->CollisionTest(gnome)) 
        {
            return item;
        }

        if (mLoading)
        {
            mLoading = false;
            return nullptr;
        }
    }
    return nullptr;
}

/** 
* Loses the game
* Resets the level / scoreboard and returns the gnome 
* back to the starting position 
*/
void CGame::Lose()
{
    mLose = true;
    mGnome->SetImmobile(true);
}

/**
 * Removes the Money object from the game
 * 
 * \param money The Money object to be removed
 */
void CGame::RemoveMoney(CMoney* money)
{
    int index = 1;

    for (auto item : mItems)
    {
        if (item.get() == money)
        {
            mDelete.push_back(item);
        }

        index++;
    }
}

/**
 * Removes the Tuition-Up object from the game
 *
 * \param tuitionUp The Tuition-Up object to be removed
 */
void CGame::RemoveTuitionUp(CTuitionUp* tuitionUp)
{
    int index = 1;

    for (auto item : mItems)
    {
        if (item.get() == tuitionUp)
        {
            mDelete.push_back(item);
        }

        index++;
    }
}

/** Accept a visitor for the collection
 * \param visitor The visitor for the collection
 */
void CGame::Accept(CItemVisitor* visitor)
{
    for (auto item : mItems)
    {
        item->Accept(visitor);
    }
}

