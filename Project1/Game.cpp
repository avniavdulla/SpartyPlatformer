/**
 * \file Game.cpp"Gnome.h"
 *
 * \author Sean Nguyen
 */

#include "pch.h"
#include "Game.h"
#include "Level.h"
#include "Gnome.h"

 // Testing includes
#include "Item.h"
#include "Background.h"
#include "Obstacle.h"
#include "Platform.h"

using namespace std;
using namespace Gdiplus;

/// Game area height in virtual pixels
const static int Height = 1024;

/**
 * Constructor
 */
CGame::CGame()
{
    auto platform = make_shared<CPlatform>(&mLevel);
    platform->SetLocation(400, 976);
    platform->SetDimensions(160, 32);
    mLevel->Add(platform);
    auto gnome = make_shared<CGnome>(&mLevel);
    gnome->SetLocation(572, 468);
    mLevel->Add(gnome);
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
    // auto scroll = (float)mLevel->GetGnome()->GetX() + virtualWidth / 2.0f;
    auto scroll = 0;
    mLevel->Draw(graphics, scroll);
}

/**
 * Handle updates for animation
 * \param elapsed The time since the last update
 */
void CGame::Update(double elapsed)
{
    mLevel->Update(elapsed);
}

std::unique_ptr<CItem> CGame::CollisionTest(CGnome* gnome)
{
    
    return std::unique_ptr<CItem>();
}
