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

/**
* Load the attributes for an item node
*
* \param node The Xml node we are loading the item from
*/
void CPlatform::XmlDeclare(std::shared_ptr<xmlnode::CXmlNode> node)
{
    CItem::XmlDeclare(node);
    mFileLeft = node->GetAttributeValue(L"left-image", L"");
    mFileRight = node->GetAttributeValue(L"right-image", L"");

    SetPlatformImage(mFileLeft, mFileRight);
}

/**
 * Set the image file to draw for the Platform
 * \param left The filename for the left of the Platform. Blank files are allowed
 * \param right The filename for the right of the Platform. Blank files are allowed
 */
void CPlatform::SetPlatformImage(const std::wstring& left, const std::wstring& right)
{
    if (!left.empty())
    {
        wstring filename = ImagesDirectory + left;
        mImageLeft = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
        if (mImageLeft->GetLastStatus() != Ok)
        {
            wstring msg(L"Failed to open ");
            msg += filename;
            AfxMessageBox(msg.c_str());
            return;
        }
    }
    else
    {
        mImageLeft.release();
    }

    if (!right.empty())
    {
        wstring filename = ImagesDirectory + right;
        mImageRight = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
        if (mImageRight->GetLastStatus() != Ok)
        {
            wstring msg(L"Failed to open ");
            msg += filename;
            AfxMessageBox(msg.c_str());
            return;
        }
    }
    else
    {
        mImageRight.release();
    }

    mFileLeft = left;
    mFileRight = right;
}