/**
 * \file Money.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"

#include <string>
#include "Money.h"
#include "Game.h"

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
 * Draw the Money
 *
 * \param graphics The graphics context to draw on
 * \param scroll The scroll offset
 */
void CMoney::Draw(Gdiplus::Graphics* graphics, float scroll)
{
    if (GetImage() != nullptr)
    {
        double width = GetWidth();
        double height = GetHeight();

        if (!mCollected)
        {
            graphics->DrawImage(GetImage().get(),
                float(GetX() - width / 2) + (float)scroll, float(GetY() - height / 2),
                (float)width, (float)height);
        }
        else
        {
            graphics->DrawImage(GetImage().get(),
                float(GetX() - width / 2) + (float)scroll, float(GetY() - height / 2) - mFly,
                (float)width, (float)height);

            FontFamily fontFamily(L"Arial");
            Gdiplus::Font font(&fontFamily, 30, FontStyleBold);

            SolidBrush green(Color(79, 160, 66));
            wstring valueLabel = L"$" + to_wstring(mValue);

            graphics->DrawString(valueLabel.c_str(), -1, &font, 
                PointF(float(GetX() - width / 2) + (float)scroll, float(GetY() - height / 2)), 
                &green);
        }
    }
}

/**
 * Handle updates in time of the Money
 * This is called before we draw and allows us to
 * move the Money.
 * \param elapsed Time elapsed since the class call
 */
void CMoney::Update(double elapsed)
{
    if (mCollected)
    {
        mFly += mSpeed * elapsed;

        if (float(GetY() - GetHeight() / 2) < 112)
        {
           // GetGame()->RemoveMoney(this);
        }
    }
}

/**
 * Tests if any other item is colliding with it
 * \param item Item testing for a collision
 */
bool CMoney::CollisionTest(CItem* item)
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

    mCollected = true;
    return false;
}