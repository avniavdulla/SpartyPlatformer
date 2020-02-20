/**
 * \file DeclarePlatform.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"
#include <string>
#include "DeclarePlatform.h"
#include "Platform.h"

using namespace std;
using namespace Gdiplus;

/**
 * Constructor
 * \param level Level this Platform is a member of
 */
CDeclarePlatform::CDeclarePlatform()
{
}

/**
 *  Destructor
 */
CDeclarePlatform::~CDeclarePlatform()
{
}

/**
 * Load the attributes for an item node
 *
 * \param node The Xml node we are loading the item from
 */
void CDeclarePlatform::XmlDeclare(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    CDeclare::XmlDeclare(node);

    mFileLeft = node->GetAttributeValue(L"left-image", L"");
    mFileMid = node->GetAttributeValue(L"mid-image", L"");
    mFileRight = node->GetAttributeValue(L"right-image", L"");

    SetPlatformImage(mFileLeft, mFileMid, mFileRight);
}

/**
 * Loads attributes for Platforms
 *
 * \param node The Xml Node we are loading the Declare from
 */
shared_ptr<CItem> CDeclarePlatform::XmlItem(const shared_ptr<CXmlNode>& node, CGame* game)
{
    shared_ptr<CPlatform> item;
    item = make_shared<CPlatform>(game);

    double x = node->GetAttributeDoubleValue(L"x", 0);
    double y = node->GetAttributeDoubleValue(L"y", 0);
    double width = node->GetAttributeDoubleValue(L"width", 0);
    double height = node->GetAttributeDoubleValue(L"height", 0);

    item->SetLocation(x, y);
    item->SetDimensions(width, height);
    item->SetPlatformImage(GetImageLeft(), GetImageMid(), GetImageRight());

    return item;
}

/**
 * Set the image file to draw for the Platform
 * \param left The filename for the left of the Platform. Blank files are allowed
 * \param left The filename for the middle of the Platform. Blank files are allowed
 * \param right The filename for the right of the Platform. Blank files are allowed
 */
void CDeclarePlatform::SetPlatformImage(const std::wstring& left, const std::wstring& mid, const std::wstring& right)
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

    if (!mid.empty())
    {
        wstring filename = ImagesDirectory + mid;
        mImageMid = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
        if (mImageMid->GetLastStatus() != Ok)
        {
            wstring msg(L"Failed to open ");
            msg += filename;
            AfxMessageBox(msg.c_str());
            return;
        }
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

    mFileLeft = left;
    mFileMid = mid;
    mFileRight = right;
}