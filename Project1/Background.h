/**
 * \file Background.h
 *
 * \author Sean Nguyen
 *
 * Class that represents the Background
 */

#pragma once

#include "Item.h"
#include "DeclareBackground.h"

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

    virtual void Draw(Gdiplus::Graphics* graphics, int scroll) override;

    virtual bool CollisionTest(CItem* item) override;

private:
    /// Associated Declaration class
    std::shared_ptr<CDeclareBackground> mDeclare;
};

