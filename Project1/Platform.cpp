/**
 * \file Platform.cpp
 *
 * \author Sean Nguyen
 */


#include "pch.h"
#include <string>
#include "Platform.h"

using namespace std;
using namespace Gdiplus;

/*
 * Constructor
 * \param level Level this Platform is a member of
 */
CPlatform::CPlatform(CGame* game) : CObstacle(game)
{
}

/**
 *  Destructor
 */
CPlatform::~CPlatform()
{
}

/**
 * Draw our Item
 *
 * \param graphics The graphics context to draw on
 * \param scroll The scroll offset
 */
void CPlatform::Draw(Gdiplus::Graphics* graphics, int scroll)
{
    double width = mImageLeft->GetWidth();
    double height = mImageLeft->GetHeight();

    for (int i = 0; i < CObstacle::GetWidth(); i += width)
    {
        if (i == 0)
        {
            graphics->DrawImage(mImageLeft.get(),
                float(GetX() - CObstacle::GetWidth() / 2) + i + (float)scroll, float(GetY() - height / 2),
                (float)width + 1, (float)height);
        }
        else if (i == CObstacle::GetWidth() - width)
        {
            graphics->DrawImage(mImageRight.get(),
                float(GetX() - CObstacle::GetWidth() / 2) + i + (float)scroll, float(GetY() - height / 2),
                (float)width + 1, (float)height);
        }
        else {
            graphics->DrawImage(mImageMid.get(),
                float(GetX() - CObstacle::GetWidth() / 2) + i + (float)scroll, float(GetY() - height / 2),
                (float)width + 1, (float)height);
        }
    }
}

/**
 * Set the image file to draw for the Platform
 * \param left The filename for the left of the Platform. Blank files are allowed
 * \param right The filename for the right of the Platform. Blank files are allowed
 */
void CPlatform::SetPlatformImage(std::shared_ptr<Gdiplus::Bitmap> left, std::shared_ptr<Gdiplus::Bitmap> mid, std::shared_ptr<Gdiplus::Bitmap> right)
{
    mImageLeft = left;
    mImageMid = mid;
    mImageRight = right;
}

/**
 * Tests if any other item is colliding with it
 * Backgrounds do not collide with anything
 * \param gnome testing for a collision
 */
bool CPlatform::CollisionTest(CItem* item)
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


    return true;
}