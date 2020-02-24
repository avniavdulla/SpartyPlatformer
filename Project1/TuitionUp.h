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

    virtual bool CollisionTest(CItem* item) override;

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitTuitionUp(this); }
};

