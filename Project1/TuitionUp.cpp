/**
 * \file TuitionUp.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"

#include "TuitionUp.h"
#include "Game.h"
#include "MoneyVisitor.h"

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
    if (!mCollected)
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

        CMoneyVisitor visitor;
        GetGame()->Accept(&visitor);
        GetGame()->RemoveTuitionUp(this);
        mCollected = true;
    }

    return false;
}