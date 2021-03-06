/**
 * \file Level.h
 *
 * \author Sean Nguyen
 *
 * Class that represents a Level
 */

#pragma once

#include <memory>
#include <vector>
#include <iterator> 
#include <map>

#include "Item.h"
#include "Declare.h"

/**
* Represents a level
*/
class CLevel
{
public:
    CLevel();

    virtual ~CLevel();

    void Add(std::shared_ptr<CItem> item);

    /** Sets the Level dimensions
     * \param width Width of Level in pixels
     * \param height Height of Level in pixels */
    void SetDimensions(double width, double height) { mWidth = width; mHeight = height; }

    void SetLevel(int levelNum);

    /** Sets starting position
     * \param x Starting X position
     * \param y Starting Y position */
    void SetStart(double x, double y) { mStart.Set(x, y); }

    void Install(CGame* game);

    void Reset();

    /** Gets Level's height
     * \return Height of Level in pixels */
    double GetHeight() { return mHeight; }

    /** Gets starting position
     * \return Vector Starting position */
    CVector GetStart() { return mStart; }

    /** Gets Level Number
     * \return Number of Level */
    int GetLevelNum() { return mLevelNum; }

    /** Gets collection of Items
     * \return Vector of Items */
    std::vector<std::shared_ptr<CItem> > GetItems() { return mItems; }

private:
    void XmlDeclare(const std::shared_ptr<xmlnode::CXmlNode>& node);

    void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node, CGame* game);

    /// The Items contained in our Level
    std::vector<std::shared_ptr<CItem> > mItems;

    /// The filename of the Level
    std::wstring mFile;

    /// The number of the Level
    int mLevelNum = 1;

    // Level dimensions
    double mHeight = 1024; ///< Height of the level in pixels
    double mWidth = 1024; ///< Width of the level in pixels

    /// Start Vector for the Gnome;
    CVector mStart;

    /// The Declares of Items
    std::map<std::wstring, std::shared_ptr<CDeclare> > mDeclares;
};