/**
* \file Gnome.h
*
* \author Avni Avdulla
*
* Represents the player-controlled Gnome
*/

#pragma once

#include "Item.h"
#include "Vector.h"

class CGnome : public CItem
{
public:
    CGnome(CGame* game);

    /// Default constructor (disabled)
    CGnome() = delete;

    /// Copy constructor (disabled)
    CGnome(const CGnome&) = delete;

    ~CGnome();

    void Update(double elapsed);

    void Reset();

    /// Sets the Gnome to move right
    void GoLeft(bool move) { mLeft = move; }

    /// Sets the Gnome to move right
    void GoRight(bool move) { mRight = move; }

    void Jump(bool move) { mJump = true; };

private:
    bool mLeft = false;

    bool mRight = false;

    bool mJump = false;
    double mWalk = 0;

    CVector mVelocity;
};