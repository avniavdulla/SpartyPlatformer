/**
 * \file Money.h
 *
 * \author Sean Nguyen
 *
 * Class that represents the Money
 */

#pragma once

#include "Item.h"

/**
 * Represents the Money
 */
class CMoney : public CItem
{
public:
    CMoney(CGame* game);

    /// Default constructor (disabled)
    CMoney() = delete;

    /// Copy constructor (disabled)
    CMoney(const CMoney&) = delete;

    ~CMoney();

    virtual bool CollisionTest(CItem* item) override;

    /** Set the value for this Money
    * \param value Value of the Money */
    void SetValue(int value) { mValue = value; }

    /** Get the value for this Money
    * \returns Value of the Money */
    int GetValue() { return mValue; }

private:
    /// The value of the Money
    int mValue = 100;
};

