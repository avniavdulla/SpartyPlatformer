/**
 * \file Background.h
 *
 * \author Sean Nguyen
 *
 * Class that represents the Background
 */

#pragma once

#include "Item.h"

/**
 * Represents the Background
 */
class CBackground : public CItem
{
public:
    CBackground(CGame* game);

    /// Default constructor (disabled)
    CBackground() = delete;

    /// Copy constructor (disabled)
    CBackground(const CBackground&) = delete;

    ~CBackground();

    virtual void Draw(Gdiplus::Graphics* graphics, float scroll) override;

    virtual bool CollisionTest(CItem* item) override;

    /**
     * Accept a visitor
     * \param visitor Visitor to accept to visit Background
     * \return Void
     */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitBackground(this); }
};

