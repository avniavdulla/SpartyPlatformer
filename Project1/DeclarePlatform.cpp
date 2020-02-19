/**
 * \file DeclarePlatform.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"
#include <string>
#include "DeclarePlatform.h"

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
void CDeclarePlatform::XmlDeclare(std::shared_ptr<xmlnode::CXmlNode> node)
{
    CDeclaration::XmlDeclare(node);
    mFileLeft = node->GetAttributeValue(L"left-image", L"");
    mFileRight = node->GetAttributeValue(L"right-image", L"");

    SetPlatformImage(mFileLeft, mFileRight);
}

/**
 * Set the image file to draw for the Platform
 * \param left The filename for the left of the Platform. Blank files are allowed
 * \param right The filename for the right of the Platform. Blank files are allowed
 */
void CDeclarePlatform::SetPlatformImage(const std::wstring& left, const std::wstring& right)
{
    /*if (!left.empty())
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
    }*/

    mFileLeft = left;
    mFileRight = right;
}