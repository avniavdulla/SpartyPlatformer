/**
 * \file Checkpoint.h
 *
 * \author Sean Nguyen
 *
 * Class that represents the Checkpoint
 * Sets a new spawn point for the Gnome
 */

#pragma once
#include "Item.h"

/**
 * Class that represents the Checkpoint
 */
class CCheckpoint : public CItem
{
public:
    CCheckpoint(CGame* game);

    /// Default constructor (disabled)
    CCheckpoint() = delete;

    /// Copy constructor (disabled)
    CCheckpoint(const CCheckpoint&) = delete;

    ~CCheckpoint();

    virtual void Draw(Gdiplus::Graphics* graphics, float scroll) override;

    void Update(double elapsed);

    virtual bool CollisionTest(CItem* item) override;

    /** Accept a visitor
     * \param visitor The visitor we accept 
     * \return Void
     */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitCheckpoint(this); }

    /** Unsets the Checkpoint */
    void UnsetCheckpoint() { mSet = false; mFly = 0; mTextSize = 20; }

private:
    /// True if checkpoint is the current spawn point
    bool mSet = false;

    /// Offset for drawing the Text flying away
    float mFly = 0;

    /// Text size as Text flies away
    float mTextSize = 20;
};