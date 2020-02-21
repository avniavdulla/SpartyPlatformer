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
 * \param game Game this Platform is a member of
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
 * Draw our Platform
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