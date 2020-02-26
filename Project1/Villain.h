/**
 * \file Villain.h
 *
 * \author Sean Nguyen
 *
 * Represents the Villain
 */

#pragma once

#include "Item.h"

/**
 * Represents the Villain
 */
class CVillain : public CItem
{
public:
    CVillain(CGame* game);

    /// Default constructor (disabled)
    CVillain() = delete;

    /// Copy constructor (disabled)
    CVillain(const CVillain&) = delete;

    ~CVillain();

    /** Sets the height range a Villain moves about in */
    void SetRangeHeight() { mMaxHeight = GetY() - 300;  mMinHeight = GetY(); }

    void Update(double elapsed);

    virtual bool CollisionTest(CItem* item) override;

    /** Accept a visitor
     * \param visitor The visitor we accept
     * \return Void */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitVillain(this); }

private:
    /// Maximum height Villain can travel to
    double mMaxHeight = 0;
    
    /// Minimum height Villain can travel to
    double mMinHeight = 0;

    /// Speed of Villain
    double mSpeed = 240;
};

