/**
 * \file Villain.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"

#include <string>

#include "Villain.h"
#include "Game.h"

using namespace std;

/**
 * Constructor
 * \param level Level this Villain is a member of
 */
CVillain::CVillain(CGame* game) : CItem(game)
{
}

/**
 *  Destructor
 */
CVillain::~CVillain()
{
}

/**
 * Handle updates in time of the Villain
 * This is called before we draw and allows us to
 * move our Villain.
 * \param elapsed Time elapsed since the class call
 */
void CVillain::Update(double elapsed)
{
    SetLocation(GetX(), GetY() + mSpeed * elapsed);

    if (mSpeed < 0 && GetY() <= mMaxHeight)
    {
        mSpeed = -mSpeed;
    }
    else if (mSpeed > 0 && GetY() >= mMinHeight)
    {
        mSpeed = -mSpeed;
    }
}

bool CVillain::CollisionTest(CItem* item)
{
    // Border for the item
    auto itemLeft = item->GetX() - item->GetWidth() / 2;
    auto itemRight = item->GetX() + item->GetWidth() / 2;
    auto itemTop = item->GetY() - item->GetHeight() / 2;
    auto itemBottom = item->GetY() + item->GetHeight() / 2;

    // For us
    auto ourLeft = GetX() - GetWidth() / 2;
    auto ourRight = GetX() + GetWidth() / 2;
    auto ourTop = GetY() - GetHeight() / 2;
    auto ourBottom = GetY() + GetHeight() / 2;

    // Test for all of the non-collision cases,
    // cases where there is a gap between the two items
    if (ourRight < itemLeft ||  // Completely to the left
        ourLeft > itemRight ||  // Completely to the right
        ourTop > itemBottom ||  // Completely below
        ourBottom < itemTop)    // Completely above
    {
        return false;
    }
    GetGame()->Lose();
    return true;
}

