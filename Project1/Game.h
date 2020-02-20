/**
 * \file Game.h
 *
 * \author Sean Nguyen
 *
 * Class that represents the Game.
 */

#pragma once

#include <iterator> 
#include <map>

#include "Level.h"
#include "Item.h"
#include "Declaration.h"
#include "Gnome.h"
#include "Scoreboard.h"
#include "XmlNode.h"

 /**
  * Represents the Game
  */
class CGame
{
public:
    CGame();

    void OnDraw(Gdiplus::Graphics* graphics, int width, int height);

    void Update(double elapsed);

    void Add(std::shared_ptr<CItem> item);

    void Clear();

    void Load(const std::wstring& filename);

    std::shared_ptr<CGnome> GetGnome() { return mGnome; }

    std::shared_ptr<CItem> CollisionTest(CGnome* gnome);

private:
    void XmlDeclaration(const std::shared_ptr<xmlnode::CXmlNode>& node);

    void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);

    /// Scale of the Game dependent on window size
    float mScale = 0.0;

    /// An object that describes the current Level
    CLevel mLevel;

    /// An object that describes the Scoreboard
    CScoreboard mScoreboard;

    // The player-controlled Gnome object
    std::shared_ptr<CGnome> mGnome;

    /// The Items contained in our Level
    std::vector<std::shared_ptr<CItem> > mItems;

    /// The Nodes associated with Item Ids
    std::map<std::wstring, std::shared_ptr<CXmlNode> > mItemIds;

    /// The Declarations of Items
    std::map<std::wstring, std::shared_ptr<CDeclaration> > mDeclarations;
};