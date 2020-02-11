/**
* \file Level.h
* \author Avni Avdulla
*/


#pragma once
#include<memory>
#include<vector>
#include"Item.h"
#include"Game.h"

using namespace Gdiplus;

class CGame;

/**
* Class representing a level
*/
class CLevel
{
public:
	//default contructor deleted
	CLevel();
	~CLevel();

	/// copy constructor disabled
	CLevel(const CLevel&) = delete;

	void Add(std::shared_ptr<CItem> item);


private:
	std::unique_ptr<Gdiplus::Bitmap> mBackground; ///< Background image
	
	/// holds all items that could go in a level
	std::vector<std::shared_ptr<CItem> >mItems; 

	CGame mGame;

};

