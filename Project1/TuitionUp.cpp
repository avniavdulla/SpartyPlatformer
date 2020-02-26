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
using namespace Gdiplus;

/// Horizontal character speed in pixels per second
const double Speed = 800.0;

/// Growth rate of Tuition Up text
const double TextGrow = 40.0;

/// Offset for Out of Bounds
const double OutOfBounds = 100;

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
 * Draw the Tuition Up
 *
 * \param graphics The graphics context to draw on
 * \param scroll The scroll offset
 */
void CTuitionUp::Draw(Gdiplus::Graphics* graphics, float scroll)
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
                float(GetX() - width / 2) + (float)scroll, float(GetY() - height / 2) + mFly,
                (float)width, (float)height);

            FontFamily fontFamily(L"Arial");
            Gdiplus::Font font(&fontFamily, mTextSize, FontStyleBold);

            StringFormat stringFormat = new StringFormat();
            stringFormat.SetAlignment(StringAlignmentCenter);

            SolidBrush green(Color(79, 160, 66));
            wstring valueLabel = L"Tuition Increase!";

            graphics->DrawString(valueLabel.c_str(), -1, &font,
                PointF(GetX() + (float)scroll, GetY() - mFly),
                &stringFormat, &green);
        }
    }
}

/**
 * Handle updates in time of the Tuition Up
 * This is called before we draw and allows us to
 * move the Tuition Up.
 * \param elapsed Time elapsed since the class call
 */
void CTuitionUp::Update(double elapsed)
{
    if (mCollected)
    {
        mFly += Speed * elapsed;
        mTextSize += TextGrow * elapsed;

        if (GetY() - mFly < -OutOfBounds)
        {
            GetGame()->RemoveTuitionUp(this);
        }
    }
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
        mCollected = true;
    }

    return false;
}