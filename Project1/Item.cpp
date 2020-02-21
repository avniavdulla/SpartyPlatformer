/**
 * \file Item.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"

#include <string>
#include "Item.h"
#include "Game.h"
#include "XmlNode.h"

using namespace std;
using namespace Gdiplus;
using namespace xmlnode;

/// The directory containing the file images
const wstring CItem::ImagesDirectory = L"images/";

/**
 * Constructor
 * \param game The Game this Item is contained in
 */
CItem::CItem(CGame* game) : mGame(game)
{
}

/**
 * Destructor
 */
CItem::~CItem()
{
}

/**
 * Draw our Item
 *
 * \param graphics The graphics context to draw on
 * \param scroll The scroll offset
 */
void CItem::Draw(Gdiplus::Graphics* graphics, float scroll)
{
    if (mImage != nullptr)
    {
        double width = GetWidth();
        double height = GetHeight();

        graphics->DrawImage(mImage.get(),
            float(GetX() - width / 2) + (float)scroll, float(GetY() - height / 2),
            (float)width, (float)height);
    }
}

/**
 * Set the image file to draw
 * \param file The base filename. Blank files are allowed
 */
void CItem::SetImage(const wstring& file)
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
}

/**
* This is the  base class version that tests for collisions
*
* \param item The Item we are testing collision against
*/
bool CItem::CollisionTest(CItem* item)
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