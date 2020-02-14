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

	/**
	* Function used to draw an item
	* \param graphics Graphics context to draw on
	*/
	virtual void Draw(Gdiplus::Graphics* graphics);

	/** The directory were the images are stored */
	static const std::wstring ImagesDirectory;

protected:
	CItem(CLevel* level);

private:
	CLevel *mLevel;

	std::string mID = ""; ///< item ID
	
	std::unique_ptr<Gdiplus::Bitmap> mImage; ///< item Image

	std::wstring mFile; ///< The file for this Item

	CVector mP; // < item position
};

