/**
 * \file Platform.h
 *
 * \author Sean Nguyen
 *
 * Represents a Platform
 */

#pragma once

#include "Obstacle.h"

class CPlatform : public CObstacle
{
public:
    CPlatform(CGame* game);

    /// Default constructor (disabled)
    CPlatform() = delete;

    /// Copy constructor (disabled)
    CPlatform(const CPlatform&) = delete;

    ~CPlatform();

    virtual void Draw(Gdiplus::Graphics* graphics, int scroll) override;

    virtual void XmlDeclare(std::shared_ptr<xmlnode::CXmlNode> node);

    void SetPlatformImage(const std::wstring& left, const std::wstring& right);

private:
    /// The image of the left Platform
    std::unique_ptr<Gdiplus::Bitmap> mImageLeft;

    /// The file for the left Platform
    std::wstring mFileLeft;

    /// The image of the right Platform
    std::unique_ptr<Gdiplus::Bitmap> mImageRight;

    /// The file for the right Platform
    std::wstring mFileRight;
};