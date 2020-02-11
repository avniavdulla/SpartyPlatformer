/**
 * \file Item.h
 *
 * \author Hugh Wilson
 *
 * Class for items to be used in the game
 */

#pragma once
class CItem
{
	///Constructor - Uses the game it is part of 
	///Game doesn't exist rn but this should be fine once it does
	CItem(CGame* game);

	///Default Constructor Disabled
	CItem() = delete;
	///Copy Constructor Disabled
	CItem(const CItem&) = delete;

	///
	int GetX() { return mPosX;	}

private:
	CGame mGame;
	int mPosX;
};

