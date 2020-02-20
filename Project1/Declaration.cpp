/**
 * \file Declaration.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"
#include "Declaration.h"

using namespace std;
using namespace Gdiplus;
using namespace xmlnode;

/// The directory containing the file images
const std::wstring CDeclaration::ImagesDirectory = L"images/";

/**
 * Constructor
 */
CDeclaration::CDeclaration()
{
}

/**
 * Destructor
 */
CDeclaration::~CDeclaration()
{
}

/**
 * Set the image file to draw
 * \param file The base filename. Blank files are allowed
 */
void CDeclaration::SetImage(const std::wstring& file)
{
    if (!file.empty())
    {
        wstring filename = ImagesDirectory + file;
        mImage = shared_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
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
* common to all Declarations. Override this to load custom attributes
* for specific items.
*
* \param node The Xml node we are loading the item from
*/
void CDeclaration::XmlDeclare(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    mFile = node->GetAttributeValue(L"image", L"");
    SetImage(mFile);
}