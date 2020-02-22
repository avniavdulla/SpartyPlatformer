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
#include "Gnome.h"
#include "Scoreboard.h"
#include "Money.h"
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

    void Load(int levelNum);

    void NextLevel();

    std::shared_ptr<CGnome> GetGnome() { return mGnome; }

    std::shared_ptr<CItem> CollisionTest(CGnome* gnome);
    /// getter for level height 
    double GetLevelHeight() { return mLevel.GetHeight(); }
    /// getter for level number
    int GetLevelNumber() { return mLevel.GetLevelNum(); }
    void Lose();

    void RemoveMoney(CMoney* money);

    /**
     * Gets list of Items in the Game
     * \return List of Items
     */
    std::vector<std::shared_ptr<CItem> > GetItems() { return mItems; }

private:

    /// Scale of the Game dependent on window size
    float mScale = 0.0;

    /// An object that describes the current Level
    CLevel mLevel;

    /// An object that describes the Scoreboard
    CScoreboard mScoreboard;

    // The player-controlled Gnome object
    std::shared_ptr<CGnome> mGnome;

    /// The Items contained in our Game
    std::vector<std::shared_ptr<CItem> > mItems;

};