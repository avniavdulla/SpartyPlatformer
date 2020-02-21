/**
 * \file Money.cpp
 *
 * \author Sean Nguyen
 */


#include "pch.h"
#include "Money.h"

using namespace std;
using namespace Gdiplus;

/**
 * Constructor
 * \param game The Game this Money is a member of
 */
CMoney::CMoney(CGame* game) : CItem(game)
{
}

/**
 *  Destructor
 */
CMoney::~CMoney()
{
}

/**
 * Tests if any other item is colliding with it
 * \param item Item testing for a collision
 */
bool CMoney::CollisionTest(CItem* item)
{
    return false;
}