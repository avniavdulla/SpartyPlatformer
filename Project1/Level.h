/**
 * \file Level.h
 *
 * \author Sean Nguyen
 *
 * Class that represents a Level
 */

#pragma once

#include<memory>
#include<vector>

#include "Item.h"

/**
* Represents a level
*/
class CLevel
{
public:
    CLevel();

    virtual ~CLevel();

    void Add(std::shared_ptr<CItem> item);

    void SetDimensions(double width, double height) { mWidth = width; mHeight = height; }

    void SetStart(double x, double y) { mStart.Set(x, y); }

    void Install(CGame* game);

    void Reset();

    CVector GetStart() { return mStart; }

private:
    /// The Items contained in our Level
    std::vector<std::shared_ptr<CItem> > mItems;

    // Level dimensions
    double mHeight = 1024; ///< Height of the level in pixels
    double mWidth = 1024; ///< Width of the level in pixels

    /// Start Vector for the Gnome;
    CVector mStart;
};