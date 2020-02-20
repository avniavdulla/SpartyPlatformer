/**
 * \file Item.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"
#include <string>
#include "Item.h"
#include "Game.h"
#include "Declaration.h"
#include "XmlNode.h"

using namespace std;
using namespace Gdiplus;
using namespace xmlnode;

/// The directory containing the file images
const std::wstring CItem::ImagesDirectory = L"images/";

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
void CItem::Draw(Gdiplus::Graphics* graphics, int scroll)
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

    mFile = file;
}

/**
 * Returns the image file to draw
 */
//unique_ptr<Bitmap> CItem::GetImage()
//{
//    wstring filename = ImagesDirectory + mFile;
//    return unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
//}

/**
* This is the  base class version that loads the attributes
* common to all Items. Override this to load custom attributes
* for specific items.
*
* \param node The Xml node we are loading the item from
*/
//void CItem::XmlDeclare(std::shared_ptr<xmlnode::CXmlNode> node)
//{
//    if (node->GetAttributeValue(L"image", L"") == L"")
//    {
//        mFile = node->GetAttributeValue(L"mid-image", L"");
//    }
//    else
//    {
//        mFile = node->GetAttributeValue(L"image", L"");
//    }
//
//    SetImage(mFile);
//}

/**
* This is the  base class version that loads the attributes
* common to all Items. Override this to load custom attributes
* for specific items.
*
* \param node The Xml node we are loading the item from
*/
void CItem::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    double x = node->GetAttributeDoubleValue(L"x", 0);
    double y = node->GetAttributeDoubleValue(L"y", 0);

    mPos.Set(x, y);

    mImage = GetDeclaration()->GetImage();
    mFile = GetDeclaration()->GetFile();
}

/**
* This is the  base class version that tests for collisions
*
* \param item The Item we are testing collision against
*/
bool CItem::CollisionTest(CItem* item)
{
    if (item == this) { return false; }
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

/**
* This is the  base class version that tests for collisions
*
* \param item The Item we are testing collision against
*/
bool CItem::VerticalCollision(CItem* item) {
    
    // Border for the item
    auto itemTop = item->GetY() - item->GetHeight() / 2;
    auto itemBottom = item->GetY() + item->GetHeight() / 2;

    //border for our item
    auto ourTop = GetY() - GetHeight() / 2;
    auto ourBottom = GetY() + GetHeight() / 2;

    if (ourTop > itemBottom || //completley below 
        ourBottom < itemTop) //completley above
    {
        return false;
    }
    return true;
}