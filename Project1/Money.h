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

    virtual void Draw(Gdiplus::Graphics* graphics, float scroll) override;

    void Update(double elapsed);

    virtual bool CollisionTest(CItem* item) override;

    /** Set the value for this Money
    * \param value Value of the Money */
    void SetValue(int value) { mValue = value; }

    /** Get the value for this Money
    * \returns Value of the Money */
    int GetValue() { return mValue; }

    /** Accept a visitor
     * \param visitor The visitor we accept 
     * \return Void */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitMoney(this); }

    /** Increases the value of this Money by 10% */
    void IncreaseTuition() { mValue *= 1.10;  }

private:
    /// The value of the Money
    int mValue = 100;

    /// Is false as long as Money has not yet been collected
    bool mCollected = false;

    /// Offset for drawing the Money flying away
    float mFly = 0;
};

