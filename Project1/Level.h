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

    void SetDimensions(double width, double height) { mWidth = width; mHeight = height; }

    void SetLevel(const std::wstring& filename) { mFile = filename; }

    void SetStart(double x, double y) { mStart.Set(x, y); }

    void Install(CGame* game);

    void Reset();

    /** Gets starting position
     * \return Vector Starting position */
    CVector GetStart() { return mStart; }

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

    // Level dimensions
    double mHeight = 1024; ///< Height of the level in pixels
    double mWidth = 1024; ///< Width of the level in pixels

    /// Start Vector for the Gnome;
    CVector mStart;

    /// The Declares of Items
    std::map<std::wstring, std::shared_ptr<CDeclare> > mDeclares;
};