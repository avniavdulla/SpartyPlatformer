/**
 * \file Door.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"
#include "Door.h"
#include "Game.h"

using namespace std;
using namespace Gdiplus;

/**
 * Constructor
 * \param game The Game this Background is a member of
 */
CDoor::CDoor(CGame* game) : CItem(game)
{
}

/**
 *  Destructor
 */
CDoor::~CDoor()
{
}

/**
 * Tests if any other item is colliding with it
 * \param item Item testing for a collision
 */
bool CDoor::CollisionTest(CItem* item)
{
    if (CItem::CollisionTest(item))
    {
        GetGame()->Clear();
        GetGame()->NextLevel();
        return true;
    }
    return false;
}