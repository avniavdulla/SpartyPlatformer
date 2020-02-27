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

/**
 * Class that represents the Gnome
 */
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

    /** Sets mReset
     * \param set Boolean to set mReset */
    void SetReset(bool set) { mReset = set; mImmobile = true; }

    /** Gets Gnome's Velocity
     * \return Gnome's Velocity */
    CVector GetVelocity() { return mVelocity; }

    /** Sets mLeft
     * \param move Boolean to set mLeft */
    void GoLeft(bool move) { mLeft = move; }

    /** Sets mRight
     * \param move Boolean to set mRight */
    void GoRight(bool move) { mRight = move; }

    /** Sets mJump */
    void Jump() { mJump = true; };

    /** Sets mImmobile
     * \param freeze Boolean to set mImmobile */
    void SetImmobile(bool freeze) { mImmobile = freeze; };

    /**
     * Getter for mDying
     * \return bool mDying variable
     */
    bool GetDying() { return mDying; }

    /** Accept a visitor
     * \param visitor The visitor we accept
     * \return Void */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitGnome(this); }

private:

    bool mLeft = false; ///< gnome walking left
    bool mRight = false; ///< gnome walking right 
    bool mJump = false; ///< jump initiated
    bool mDying = false; ///< gnome is dying 
    bool mReset = false; ///< checks if gnome got reset 
    bool mImmobile = true; ///< True when Gnome cannot be controlled
    double mWalk = 0; ///< keeps track of time while walking

    CVector mVelocity; ///< velocity of the gnome

};