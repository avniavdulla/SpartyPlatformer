/**
 * \file Background.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"
#include "Background.h"

using namespace std;
using namespace Gdiplus;

/**
 * Constructor
 * \param game The Level this Game is a member of
 */
CBackground::CBackground(CGame* game) : CItem(game)
{
}

/**
 *  Destructor
 */
CBackground::~CBackground()
{
}

/**
 * Draw our Background
 * \param graphics The graphics context to draw on
 * \param scroll The scroll offset
 */
void CBackground::Draw(Gdiplus::Graphics* graphics, int scroll)
{
    int width = GetWidth();
    int height = GetHeight();

    graphics->DrawImage(GetImage().get(),
        int(GetX() - width / 2 ) + scroll, int(GetY() - height / 2),
        width + 1, height);
}

/**
 * Tests if any other item is colliding with it
 * Backgrounds do not collide with anything
 * \param item Item testing for a collision
 */
bool CBackground::CollisionTest(CItem* item)
{
    return false;
}