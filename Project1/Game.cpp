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
    mScoreboard.Draw(graphics, 0);
}

/**
 * Handle updates for animation
 * \param elapsed The time since the last update
 */
void CGame::Update(double elapsed)
{

    for (auto item : mItems)
    {
        item->Update(elapsed);
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
}

/**
 * Load the Game from a specified Level
 * \param filename File name of the Level
 */
void CGame::Load(int levelNum)
{
    Clear();
    mLevel.SetLevel(levelNum);
    mLevel.Install(this);
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
    Clear();
    mLevel.Reset();
    mScoreboard.Reset();
    mLevel.Install(this);
}