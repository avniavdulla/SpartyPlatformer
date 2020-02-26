/**
 * \file Door.h
 *
 * \author Sean Nguyen
 *
 * Class that represents the Door
 */

#pragma once

#include "Item.h"

/**
 * Represents the Door
 */
class CDoor : public CItem
{
public:
    CDoor(CGame* game);

    /// Default constructor (disabled)
    CDoor() = delete;

    /// Copy constructor (disabled)
    CDoor(const CDoor&) = delete;

    ~CDoor();

    virtual bool CollisionTest(CItem* item) override;

    /** Accept a visitor
     * \param visitor The visitor we accept 
     * \return Void
     */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitDoor(this); }
};

