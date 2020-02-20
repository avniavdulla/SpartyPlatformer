/**
 * \file Platform.h
 *
 * \author Sean Nguyen
 *
 * Represents a Platform
 */

#pragma once

#include "Obstacle.h"
#include "DeclarePlatform.h";

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

    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

    /**
     * Set associated Declaration
     * \param declare Associated Declaration
     */
    /*virtual void SetDeclaration(std::shared_ptr<CDeclaration> declare) { 
        declare = make_shared<CDeclarePlatform>();
        mDeclare = declare; 
    }*/

    void SetPlatformImage(std::shared_ptr<Gdiplus::Bitmap> left, std::shared_ptr<Gdiplus::Bitmap> mid, std::shared_ptr<Gdiplus::Bitmap> right);

    /**
     * Get the left image of the Platform
     * \returns Left image of the Platform
     */
    std::shared_ptr<Gdiplus::Bitmap> GetImageLeft() { return mImageLeft; }

    /**
     * Get the middle image of the Platform
     * \returns Middle image of the Platform
     */
    std::shared_ptr<Gdiplus::Bitmap> GetImageMid() { return mImageMid; }

    /**
     * Get the right image of the Platform
     * \returns Right image of the Platform
     */
    std::shared_ptr<Gdiplus::Bitmap> GetImageRight() { return mImageRight; }

private:
    /// Associated Declaration class
    std::shared_ptr<CDeclarePlatform> mDeclare;

    /// The image of the left Platform
    std::shared_ptr<Gdiplus::Bitmap> mImageLeft;

    /// The file for the left Platform
    // std::wstring mFileLeft;

    /// The image of the middle Platform
    std::shared_ptr<Gdiplus::Bitmap> mImageMid;

    /// The image of the right Platform
    std::shared_ptr<Gdiplus::Bitmap> mImageRight;

    /// The file for the right Platform
    // std::wstring mFileRight;
};