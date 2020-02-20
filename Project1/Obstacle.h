/**
 * \file Obstacle.h
 *
 * \author Sean Nguyen
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

    virtual ~CObstacle();

    /**
     * Set the Obstacle dimensions
     * \param width Width of obstacle
     * \param height Height of obstacle
     */
    void SetDimensions(int width, int height) { mWidth = width; mHeight = height; }

    /**
     * The width of the Obstacle
     * \returns Width of the Obstacle in pixels
     */
    virtual int GetWidth() const override { return mWidth; }

    /**
     * The height of the Obstacle
     * \returns Height of the Obstacle in pixels
     */
    virtual int GetHeight() const override { return mHeight; }

protected:
    CObstacle(CGame* game);

private:
    /// Width of Obstacle
    int mWidth = 0;

    /// Height of Obstacle
    int mHeight = 0;
};

