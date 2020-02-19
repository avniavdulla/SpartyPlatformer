/**
* \file Gnome.h
* \author Avni Avdulla
*/

#pragma once
#include "Item.h"
#include "Vector.h"

class CGnome :
	public CItem
{
public:
	/** 
	* Update function for gnome movement
	* \param elapsed Time since last update
	*/
	void Update(double elapsed);

private:
	
	CVector mVelocity; /// < velocity vector
};

