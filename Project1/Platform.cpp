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

/// Platform Left filename
const wstring PlatformLeftImage = L"images/platformIndustrial_059.png";

/// Platform Middle filename
const wstring PlatformMidImage = L"images/platformIndustrial_060.png";

/// Platform Right filename
const wstring PlatformRightImage = L"images/platformIndustrial_061.png";

/**
 * Constructor
 * \param level Level this Platform is a member of
 */
CPlatform::CPlatform(CLevel* level) : CObstacle(level, PlatformMidImage)
{
}

/**
 * Draw our Item
 * \param graphics The graphics context to draw on
 */
void CPlatform::Draw(Gdiplus::Graphics* graphics, int scroll)
{
    std::unique_ptr<Gdiplus::Bitmap> leftImage = unique_ptr<Bitmap>(Bitmap::FromFile(PlatformLeftImage.c_str()));
    std::unique_ptr<Gdiplus::Bitmap> midImage = unique_ptr<Bitmap>(Bitmap::FromFile(PlatformMidImage.c_str()));
    std::unique_ptr<Gdiplus::Bitmap> rightImage = unique_ptr<Bitmap>(Bitmap::FromFile(PlatformRightImage.c_str()));

    double width = midImage->GetWidth();
    double height = midImage->GetHeight();

    for (int i = 0; i <= GetWidth(); i += width)
    {
        if (i == 0)
        {
            graphics->DrawImage(leftImage.get(),
                float(GetX() - width / 2) + i + (float)scroll, float(GetY() - height / 2),
                (float)width + 1, (float)height);
        }
        else if (i == GetWidth())
        {
            graphics->DrawImage(rightImage.get(),
                float(GetX() - width / 2) + i + (float)scroll, float(GetY() - height / 2),
                (float)width + 1, (float)height);
        }
        else {
            graphics->DrawImage(midImage.get(),
                float(GetX() - width / 2) + i + (float)scroll, float(GetY() - height / 2),
                (float)width + 1, (float)height);
        }
    }
}