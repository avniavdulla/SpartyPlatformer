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
 * \param game Game this Villain is a member of
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

/**
 * Tests if any other item is colliding with it
 * \param item Item testing for a collision
 * \return False Gnome does not need to collide with a Villain as it is dead
 */
bool CVillain::CollisionTest(CItem* item)
{
    if (CItem::CollisionTest(item))
    {
        GetGame()->Lose();
    }
    return false;
}

