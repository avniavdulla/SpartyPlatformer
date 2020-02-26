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

/// Collision distance for the door in pixels
const double CollisionDistance = 20;

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
 * \return false Gnome can pass through doors
 */
bool CDoor::CollisionTest(CItem* item)
{
    // Collision for door is different
    double dx = item->GetX() - GetX();
    double dy = item->GetY() - GetY();
    double distance = sqrt(dx * dx + dy * dy);
    if (distance < CollisionDistance)
    {
        GetGame()->NextLevel();
    }

    return false;
}