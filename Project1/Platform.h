/**
 * \file Platform.h
 *
 * \author Sean Nguyen
 *
 * Represents a Platform
 */

#pragma once

#include "Obstacle.h"
#include "DeclarePlatform.h"

/**
 * Represents a Platform
 */
class CPlatform : public CObstacle
{
public:
    CPlatform(CGame* game);

    /// Default constructor (disabled)
    CPlatform() = delete;

    /// Copy constructor (disabled)
    CPlatform(const CPlatform&) = delete;

    ~CPlatform();

    virtual void Draw(Gdiplus::Graphics* graphics, float scroll) override;

    void SetPlatformImage(std::shared_ptr<Gdiplus::Bitmap> left, std::shared_ptr<Gdiplus::Bitmap> mid, std::shared_ptr<Gdiplus::Bitmap> right);

    /**
     * Get the left image of the Platform
     * \return Left image of the Platform
     */
    std::shared_ptr<Gdiplus::Bitmap> GetImageLeft() { return mImageLeft; }

    /**
     * Get the middle image of the Platform
     * \return Middle image of the Platform
     */
    std::shared_ptr<Gdiplus::Bitmap> GetImageMid() { return mImageMid; }

    /**
     * Get the right image of the Platform
     * \return Right image of the Platform
     */
    std::shared_ptr<Gdiplus::Bitmap> GetImageRight() { return mImageRight; }

    /** Accept a visitor
     * \param visitor The visitor we accept 
     * \return Void */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitPlatform(this); }

private:
    /// The image of the left Platform
    std::shared_ptr<Gdiplus::Bitmap> mImageLeft;

    /// The image of the middle Platform
    std::shared_ptr<Gdiplus::Bitmap> mImageMid;

    /// The image of the right Platform
    std::shared_ptr<Gdiplus::Bitmap> mImageRight;

};