/**
 * \file Item.h
 *
 * \author Hugh Wilson, Avni Avdulla
 *
 * Class for items to be used in the game
 */

#pragma once

#include <string>

class CItem
{
	///Constructor - Uses the game it is part of 
	///Game doesn't exist rn but this should be fine once it does
	CItem(CGame* game);

	///Default Constructor Disabled
	CItem() = delete;
	///Copy Constructor Disabled
	CItem(const CItem&) = delete;

	/**
	* Function used to draw an item
	* \param graphics Graphics context to draw on
	*/
	virtual void Draw(Gdiplus::Graphics* graphics);

private:
	CGame mGame;

	std::string mID = ""; ///< item ID
	
	std::unique_ptr<Gdiplus::Bitmap> mImage; ///< item Image

	double mPosX; ///< X position of item
	double mPosY; ///< Y position of item


};

