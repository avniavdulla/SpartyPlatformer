/**
 * \file Item.h
 *
 * \author Hugh Wilson, Avni Avdulla
 *
 * Base class for any Item in a Game
 */

#pragma once

#include <memory>

#include "XmlNode.h"
#include "Vector.h"
#include "ItemVisitor.h"

using namespace xmlnode;

class CGame;

/**
 * Base class for any Item in a Game
 */
class CItem
{
public:
    /// The directory where the images are stored
    static const std::wstring ImagesDirectory;

    /// Default constructor (disabled)
    CItem() = delete;

    /// Copy constructor (disabled)
    CItem(const CItem&) = delete;

    virtual ~CItem();

    virtual void Draw(Gdiplus::Graphics* graphics, float scroll);

    /**
     * Handle updates for animation
     * \param elapsed The time since the last update
     * \return Void
     */
    virtual void Update(double elapsed) {}

    /**
     * Sets the image to draw
     * \param image Shared Ptr of bitmap to set mImage to
     */
    void SetImage(std::shared_ptr<Gdiplus::Bitmap> image) { mImage = image; }

    void SetImage(const std::wstring &file);
    /**
     * Return the Game the Item belongs to
     * \return Game the Item belongs to
     */
    CGame* GetGame() { return mGame; }

    /**
     * The X location of the Item
     * \return X location in pixels
     */
    double GetX() const { return mPos.X(); }

    /**
     * The Y location of the Item
     * \return Y location in pixels
     */
    double GetY() const { return mPos.Y(); }

    /**
     * Set the Item location
     * \param x X location
     * \param y Y location
     */
    void CItem::SetLocation(double x, double y) { mPos.Set(x, y); }

    /**
     * Set the Item location
     * \param pos Vector location
     */
    void CItem::SetLocation(CVector pos) { mPos.Set(pos); }

    /**
     * The location of the Item
     * \return Location as a Vector
     */
    CVector CItem::GetLocation() { return mPos; }

    /**  Get the file name for this tile image
     * \return Filename or blank if none */
    std::wstring GetFile() { return mFile; }

    /**  Get the image for this Item
     * \return Image */
    std::shared_ptr<Gdiplus::Bitmap> GetImage() { return mImage; }

    /**
     * Get the width of the Item
     * \return Width of the Item
     */
    virtual int GetWidth() const { return mImage->GetWidth(); }

    /**
     * Get the height of the Item
     * \return Height of the Item
     */
    virtual int GetHeight() const { return mImage->GetHeight(); }
    
    virtual bool CollisionTest(CItem* item);

    /** Accept a visitor
     * \param visitor The visitor we accept
     * \return Void */
    virtual void Accept(CItemVisitor* visitor) = 0;

protected:
    CItem(CGame* game);
    
private:
    /// The Level this Item is contained in
    CGame* mGame;

    /// Item Vector in the Level
    CVector mPos;

    /// The image of this Item
    std::shared_ptr<Gdiplus::Bitmap> mImage;

    /// The file for this Item
    std::wstring mFile;
};