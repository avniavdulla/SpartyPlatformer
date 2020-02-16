/**
* \file Level.h
* \author Avni Avdulla
*/


#pragma once
#include<memory>
#include<vector>
#include"Item.h"
#include"Game.h"
#include "Gnome.h"

using namespace Gdiplus;

/**
* Class representing a level
*/
class CLevel
{
public:
	CLevel();
	
	virtual ~CLevel();

	void Add(std::shared_ptr<CItem> item);

	void Draw(Gdiplus::Graphics* graphics, int scroll);

	void Update(double elapsed);

private:
	std::unique_ptr<Gdiplus::Bitmap> mBackground; ///< Background image
	
	/// The player-controlled Gnome object
	CGnome* mGnome;

	/// The Items contained in our Level
	std::vector<std::shared_ptr<CItem> > mItems;

	// Level dimensions
	double mHeight = 1024; ///< Height of the level in pixels
	double mWidth = 1024; ///< Width of the level in pixels

	/// Start Vector for the Gnome;
	CVector mStart;

};

