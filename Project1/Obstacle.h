/**
 * \file Obstacle.h
 *
 * \author Avni Avdulla
 *
 * Base class for any Wall or Platform in a Level
 */

#pragma once

#include "Item.h"

class CObstacle : public CItem
{
public:
    /// Default constructor (disabled)
    CObstacle() = delete;

    /// Copy constructor (disabled)
    CObstacle(const CObstacle&) = delete;

    void SetWidth(int width) { mWidth = width; }

    void SetHeight(int height) { mHeight = height; }

    void SetDimensions(int width, int height) { mWidth = width; mHeight = height; }

    int GetWidth() { return mWidth; }

    int GetHeight() { return mHeight; }

    virtual void Draw(Gdiplus::Graphics* graphics, int scroll) override;

protected:
    CObstacle(CLevel* level, const std::wstring& filename);

private:
    /// Width of Obstacle
    int mWidth = 0;

    /// Height of Obstacle
    int mHeight = 0;
};

