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

/// Grass Left filename
const wstring GrassLeft = L"grassLeft.png";

/// Grass Right filename
const wstring GrassRight = L"grassRight.png";

/// Snow Left filename
const wstring SnowLeft = L"snowLeft.png";

/// Snow Right filename
const wstring SnowRight = L"snowRight.png";

/// Industrial Left filename
const wstring IndustrialLeft = L"platformIndustrial_059.png";

/// Industrial Right filename
const wstring IndustrialRight = L"platformIndustrial_061.png";

/**
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
    double width = GetWidth();
    double height = GetHeight();

    for (int i = 0; i < GetObstacleWidth(); i += width)
    {
        if (i == 0)
        {
            graphics->DrawImage(mImageLeft.get(),
                float(GetX() - GetObstacleWidth() / 2) + i + (float)scroll, float(GetY() - height / 2),
                (float)width + 1, (float)height);
        }
        else if (i == GetObstacleWidth() - width)
        {
            graphics->DrawImage(mImageRight.get(),
                float(GetX() - GetObstacleWidth() / 2) + i + (float)scroll, float(GetY() - height / 2),
                (float)width + 1, (float)height);
        }
        else {
            graphics->DrawImage(GetImage().get(),
                float(GetX() - GetObstacleWidth() / 2) + i + (float)scroll, float(GetY() - height / 2),
                (float)width + 1, (float)height);
        }
    }
}

///**
//* Load the attributes for an item node
//*
//* \param node The Xml node we are loading the item from
//*/
//void CPlatform::XmlDeclare(std::shared_ptr<xmlnode::CXmlNode> node)
//{
//    CItem::XmlDeclare(node);
//    mFileLeft = node->GetAttributeValue(L"left-image", L"");
//    mFileRight = node->GetAttributeValue(L"right-image", L"");
//
//    SetPlatformImage(mFileLeft, mFileRight);
//}

/**
 * Load the attributes for an item node.
 * \param node The Xml node we are loading the item from
 */
void CPlatform::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    CObstacle::XmlLoad(node);
    SetPlatformImage();
}

/**
 * Set the image file to draw for the Platform
 * \param left The filename for the left of the Platform. Blank files are allowed
 * \param right The filename for the right of the Platform. Blank files are allowed
 */
void CPlatform::SetPlatformImage()
{
    wstring file = CItem::GetFile();
    wstring filename = ImagesDirectory;

    if (file == L"grassMid.png")
    {
        filename += GrassLeft;
        mImageLeft = shared_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
        if (mImageLeft->GetLastStatus() != Ok)
        {
            wstring msg(L"Failed to open ");
            msg += filename;
            AfxMessageBox(msg.c_str());
            return;
        }

        filename += GrassRight;
        mImageRight = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
        if (mImageRight->GetLastStatus() != Ok)
        {
            wstring msg(L"Failed to open ");
            msg += filename;
            AfxMessageBox(msg.c_str());
            return;
        }
    }
    else if (file == L"snowMid.png")
    {
        filename += SnowLeft;
        mImageLeft = shared_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
        if (mImageLeft->GetLastStatus() != Ok)
        {
            wstring msg(L"Failed to open ");
            msg += filename;
            AfxMessageBox(msg.c_str());
            return;
        }

        filename += SnowRight;
        mImageRight = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
        if (mImageRight->GetLastStatus() != Ok)
        {
            wstring msg(L"Failed to open ");
            msg += filename;
            AfxMessageBox(msg.c_str());
            return;
        }
    }
    else if (file == L"platformIndustrial_060.png")
    {
        filename += IndustrialLeft;
        mImageLeft = shared_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
        if (mImageLeft->GetLastStatus() != Ok)
        {
            wstring msg(L"Failed to open ");
            msg += filename;
            AfxMessageBox(msg.c_str());
            return;
        }

        filename += IndustrialRight;
        mImageRight = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
        if (mImageRight->GetLastStatus() != Ok)
        {
            wstring msg(L"Failed to open ");
            msg += filename;
            AfxMessageBox(msg.c_str());
            return;
        }
    }
}