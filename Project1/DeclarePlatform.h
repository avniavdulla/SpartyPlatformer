/**
 * \file DeclarePlatform.h
 *
 * \author Sean Nguyen
 *
 * Represents a Platform Declaration
 */

#pragma once

#include "Declaration.h"

class CDeclarePlatform : public CDeclaration
{
public:
    CDeclarePlatform();

    /// Copy constructor (disabled)
    CDeclarePlatform(const CDeclarePlatform&) = delete;

    ~CDeclarePlatform();

    virtual void XmlDeclare(const std::shared_ptr<xmlnode::CXmlNode>& node);

    void SetPlatformImage(const std::wstring& left, const std::wstring& right);

    /**  Get the image for this Declaration
    * \returns Filename or blank if none */
    std::shared_ptr<Gdiplus::Bitmap> GetLeftImage() { return mImageLeft; }

    /**  Get the image for this Declaration
    * \returns Filename or blank if none */
    std::shared_ptr<Gdiplus::Bitmap> GetRightImage() { return mImageRight; }

private:
    /// The image of the left Platform
    std::shared_ptr<Gdiplus::Bitmap> mImageLeft;

    /// The file for the left Platform
    std::wstring mFileLeft;

    /// The image of the right Platform
    std::shared_ptr<Gdiplus::Bitmap> mImageRight;

    /// The file for the right Platform
    std::wstring mFileRight;
};

