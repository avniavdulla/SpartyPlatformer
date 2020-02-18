/**
 * \file Item.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"
#include "Item.h"
#include "Level.h"


using namespace std;
using namespace Gdiplus;

/// The directory containing the file images
const std::wstring CItem::ImagesDirectory = L"images/";

/**
 * Constructor
 * \param level The Level this Item is a member of
 */
CItem::CItem(CLevel* level) : mLevel(level)
{
}

/**
 *  Destructor
 */
CItem::~CItem()
{
}

/**
 *  Set the image file to draw
 * \param file The base filename. Blank files are allowed
 */
void CItem::SetImage(const std::wstring& file)
{
    if (!file.empty())
    {
        wstring filename = ImagesDirectory + file;
        mImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
        if (mImage->GetLastStatus() != Ok)
        {
            wstring msg(L"Failed to open ");
            msg += filename;
            AfxMessageBox(msg.c_str());
            return;
        }
    }
    else
    {
        mImage.release();
    }

    mFile = file;
}

/**
 * Draw our Item
 * \param graphics The graphics context to draw on
 */
void CItem::Draw(Gdiplus::Graphics* graphics, int scroll)
{
    double width = mImage->GetWidth();
    double height = mImage->GetHeight();

    graphics->DrawImage(mImage.get(),
        float(GetX() - width / 2) + (float)scroll, float(GetY() - height / 2),
        (float)width, (float)height);
}