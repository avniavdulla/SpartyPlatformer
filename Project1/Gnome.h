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

    void Reset(CVector start);

    /** Gets Gnome's Velocity
     * \return Gnome's Velocity */
    CVector GetVelocity() { return mVelocity; }

    /// Sets the Gnome to move right
    void GoLeft(bool move) { mLeft = move; }

    /// Sets the Gnome to move right
    void GoRight(bool move) { mRight = move; }

    void Jump(bool move) { mJump = true; };

private:

    bool mLeft = false; ///< gnome walking left
    bool mRight = false; ///< gnome walking right 
    bool mJump = false; ///< jump initiated
    bool mDying = false; ///< gnome is dying 
    double mWalk = 0; ///< keeps track of time while walking

    CVector mVelocity; ///< velocity of the gnome

};