/**
 * \file TuitionUp.h
 *
 * \author Sean Nguyen
 *
 * Class that represents the Tuition Up
 */

#pragma once

#include "Item.h"

/**
 * Represents the Tuition Up
 */
class CTuitionUp : public CItem
{
public:
    CTuitionUp(CGame* game);

    /// Default constructor (disabled)
    CTuitionUp() = delete;

    /// Copy constructor (disabled)
    CTuitionUp(const CTuitionUp&) = delete;

    ~CTuitionUp();

    virtual void Draw(Gdiplus::Graphics* graphics, float scroll) override;

    void Update(double elapsed);

    virtual bool CollisionTest(CItem* item) override;

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitTuitionUp(this); }

private:
    /// Is false as long as Tuition Up has not yet been collected
    bool mCollected = false;

    /// Offset for drawing the Text and Tuition Up flying away
    float mFly = 0;

    /// Text size as Tuition Up Text flies away
    float mTextSize = 20;
};

