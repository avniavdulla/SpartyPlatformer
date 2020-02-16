/**
 * \file Platform.h
 *
 * \author Sean Nguyen
 *
 * Represents a Platform
 */

#pragma once
#include "Obstacle.h"
class CPlatform : public CObstacle
{
public:
    CPlatform(CLevel* level);

    /// Default constructor (disabled)
    CPlatform() = delete;

    /// Copy constructor (disabled)
    CPlatform(const CPlatform&) = delete;

    virtual void Draw(Gdiplus::Graphics* graphics, int scroll) override;
};

