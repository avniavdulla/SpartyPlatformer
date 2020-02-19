/**
* \file Gnome.h
* \author Avni Avdulla
*/

#pragma once
#include "Item.h"
#include "Vector.h"
#include "Game.h"

class CLevel;

class CGnome : public CItem
{
public:

	CGnome() = delete;
	CGnome(CGnome& gnome) = delete;
	
	/** 
	* Update function for gnome movement
	* \param elapsed Time since last update
	*/
	void Update(double elapsed);
protected:

	CGnome(CLevel* level);
private:
	
	CVector mVelocity; /// < velocity vector
};

