/**
 * \file Item.h
 *
 * \author Hugh Wilson, Avni Avdulla
 *
 * Class for items to be used in the game
 */

#pragma once

#include <string>
#include "XmlNode.h"
#include "Vector.h"

class CLevel;

class CItem
{
public:
	///Default Constructor Disabled
	CItem() = delete;

	///Copy Constructor Disabled
	CItem(const CItem&) = delete;

	virtual ~CItem();

	void SetImage(const std::wstring& file);

	virtual void Draw(Gdiplus::Graphics* graphics, int scroll);

    /**
     * The X location of the item
     * \returns X location in pixels
     */
    double GetX() const { return mP.X(); }

    /**
     * The Y location of the item
     * \returns Y location in pixels
     */
    double GetY() const { return mP.Y(); }

    /** 
    * Gets the position vector of item
    * \returns mP of item
    */
    CVector GetPos() const { return mP; }

    /**
     * Set the item location
     * \param x X location
     * \param y Y location
     */
    void CItem::SetLocation(double x, double y) { mP.Set(x, y); }

    /**
     * Set the item location
     * \param pos Vector location
     */
    void CItem::SetLocation(CVector pos) { mP.Set(pos); }

    /**
     * Get the width of the Item
     * \returns Width of the Item
     */
    int GetWidth() const { return mImage->GetWidth(); }

    /**
     * Get the height of the Item
     * \returns Height of the Item
     */
    int GetHeight() const { return mImage->GetHeight(); }

    /**
     * Handle updates for animation
     * \param elapsed The time since the last update
     */
    virtual void Update(double elapsed) {}

	/** The directory were the images are stored */
	static const std::wstring ImagesDirectory;

    /// Getter for level item is currently in 
    CLevel* GetLevel() { return mLevel; }

    bool CollisionTest(CItem* item);

protected:
	CItem(CLevel* level);


private:
    
    CLevel* mLevel;  ///< level this item is contained in 

	std::string mID = ""; ///< item ID
	
	std::unique_ptr<Gdiplus::Bitmap> mImage; ///< item Image

	std::wstring mFile; ///< The file for this Item

	CVector mP; /// < item position
};

