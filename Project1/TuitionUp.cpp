/**
 * \file TuitionUp.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"

#include "TuitionUp.h"

using namespace std;

/**
 * Constructor
 * \param game The Game this Money is a member of
 */
CTuitionUp::CTuitionUp(CGame* game) : CItem(game)
{
}

/**
 *  Destructor
 */
CTuitionUp::~CTuitionUp()
{
}

/**
 * Tests if any other item is colliding with it
 * \param item Item testing for a collision
 */
bool CTuitionUp::CollisionTest(CItem* item)
{
    return false;
}