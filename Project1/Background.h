/**
 * \file Background.h
 *
 * \author Steven Wang
 *
 * Class for background in the game
 */

#pragma once
class CBackground
{
	///Constructor - Uses the game it is part of 
	///Game doesn't exist rn but this should be fine once it does
	CBackground(CGame* game);

	///Default Constructor Disabled
	CBackground() = delete;
	///Copy Constructor Disabled
	CBackground(const CItem&) = delete;

private:
	CGame mGame;
};