/**
* \file Obstacle.h
* \author Avni Avdulla,
*/

#pragma once
#include "Item.h"

/**
* Class representing an obstacle type item
*/
class CObstacle :
	public CItem
{
public:
	///deafult constructor deleted
	CObstacle() = delete;
	//default copy constructor deleted
	CObstacle(const CObstacle&) = delete;

	/**
	* Function used to draw an item
	* \param graphics Graphics context to draw on
	*/
	virtual void Draw(Gdiplus::Graphics* graphics) override;

};

