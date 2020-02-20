/**
 * \file DeclarePlatform.h
 *
 * \author Sean Nguyen
 *
 * Represents a Platform Declaration
 */

#pragma once

#include "Declare.h"

class CDeclarePlatform : public CDeclare
{
public:
    CDeclarePlatform();

    /// Copy constructor (disabled)
    CDeclarePlatform(const CDeclarePlatform&) = delete;

    ~CDeclarePlatform();

    virtual void XmlDeclare(const std::shared_ptr<xmlnode::CXmlNode>& node);

    virtual std::shared_ptr<CItem> XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node, CGame* game) override;

    void SetPlatformImage(const std::wstring& left, const std::wstring& mid, const std::wstring& right);

    /**  Get the image for this Declaration
    * \returns Filename or blank if none */
    std::shared_ptr<Gdiplus::Bitmap> GetImageLeft() { return mImageLeft; }

    /**  Get the image for this Declaration
    * \returns Filename or blank if none */
    std::shared_ptr<Gdiplus::Bitmap> GetImageMid() { return mImageMid; }

    /**  Get the image for this Declaration
    * \returns Filename or blank if none */
    std::shared_ptr<Gdiplus::Bitmap> GetImageRight() { return mImageRight; }

private:
    /// The image of the left Platform
    std::shared_ptr<Gdiplus::Bitmap> mImageLeft;

    /// The file for the left Platform
    std::wstring mFileLeft;

    /// The image of the middle Platform
    std::shared_ptr<Gdiplus::Bitmap> mImageMid;

    /// The file for the middle Platform
    std::wstring mFileMid;

    /// The image of the right Platform
    std::shared_ptr<Gdiplus::Bitmap> mImageRight;

    /// The file for the right Platform
    std::wstring mFileRight;
};

