/**
 * \file Declaration.h
 *
 * \author Sean Nguyen
 *
 * Base class for any Declaration
 */

#pragma once

#include <memory>

#include "XmlNode.h"
#include "Vector.h"

using namespace xmlnode;

/**
 * Base class for any Declaration
 */
class CDeclaration
{
public:
    /// The directory where the images are stored
    static const std::wstring ImagesDirectory;

    CDeclaration();

    /// Copy constructor (disabled)
    CDeclaration(const CDeclaration&) = delete;

    virtual ~CDeclaration();

    void SetImage(const std::wstring& file);

    /**  Get the image for this Declaration
    * \returns Image */
    std::shared_ptr<Gdiplus::Bitmap> GetImage() { return mImage; }

    /**  Get the file name for this tile image
    * \returns Filename or blank if none */
    std::wstring GetFile() { return mFile; }

    virtual void XmlDeclare(const std::shared_ptr<xmlnode::CXmlNode>& node);

private:
    /// The image of this Item
    std::shared_ptr<Gdiplus::Bitmap> mImage;

    /// The file for this Item
    std::wstring mFile;
};