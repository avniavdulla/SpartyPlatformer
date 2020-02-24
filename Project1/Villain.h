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

    void SetRangeHeight() { mMaxHeight = GetY() - 300;  mMinHeight = GetY(); }

    void Update(double elapsed);

    virtual bool CollisionTest(CItem* item) override;

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitVillain(this); }

private:
    double mMaxHeight = 0;
    
    double mMinHeight = 0;

    double mSpeed = 240;
};

