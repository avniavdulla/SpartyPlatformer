/**
 * \file Declare.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"

#include <string>
#include "Declare.h"
#include "XmlNode.h"

using namespace std;
using namespace Gdiplus;
using namespace xmlnode;

/// The directory containing the file images
const wstring CDeclare::ImagesDirectory = L"images/";

/**
 * Constructor
 */
CDeclare::CDeclare()
{
}

/**
 * Destructor
 */
CDeclare::~CDeclare()
{
}

/**
 * Set the image file to draw
 * \param file The base filename. Blank files are allowed
 */
void CDeclare::SetImage(const wstring& file)
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
 * This is the base class version that loads the attributes
 * common to all Declares. Override this to load custom attributes
 * for specific Declares.
 *
 * \param node The Xml Node we are loading the Declare from
 * \return Void
 */
void CDeclare::XmlDeclare(const shared_ptr<CXmlNode>& node)
{
    mFile = node->GetAttributeValue(L"image", L"");

    if (mFile == L"")
    {
        mFile = node->GetAttributeValue(L"left-image", L"");
    }

    SetImage(mFile);
}

/**
 * Loads attributes for Backgrounds
 *
 * \param node The Xml Node we are loading the Declare from
 * \param game The Game the created Item belongs to
 * \return Item created from the Declare and the node
 */
shared_ptr<CItem> CDeclare::XmlItem(const shared_ptr<CXmlNode>& node, CGame* game)
{
    shared_ptr<CItem> item;

    double x = node->GetAttributeDoubleValue(L"x", 0);
    double y = node->GetAttributeDoubleValue(L"y", 0);

    item->SetLocation(x, y);

    item->SetImage(GetImage());

    return item;
}