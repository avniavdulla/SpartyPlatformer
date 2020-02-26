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
#include "TuitionUp.h"
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

    /**
     * Gets the Game's Gnome
     * \return Shared Ptr to the Gnome
     */
    std::shared_ptr<CGnome> GetGnome() { return mGnome; }

    /**
     * Gets the Game's Scoreboard
     * \return Ptr to the Scoreboard
     */
    CScoreboard* GetScoreboard() { return &mScoreboard; }

    /**
     * Gets the Game's Level
     * \return Ptr to the Level
     */
    CLevel* GetLevel() { return &mLevel; }

    std::shared_ptr<CItem> CollisionTest(CGnome* gnome);

    /**
     * Gets the Game's Level's height
     * \return Level's height
     */
    double GetLevelHeight() { return mLevel.GetHeight(); }

    /**
     * Gets the Game's Level's number
     * \return Level's number
     */
    int GetLevelNumber() { return mLevel.GetLevelNum(); }

    void Lose();

    void RemoveMoney(CMoney* money);

    void RemoveTuitionUp(CTuitionUp* tuitionUp);

    void Accept(CItemVisitor* visitor);

    /** Sets starting position
     * \param x Starting X position
     * \param y Starting Y position */
    void SetStart(double x, double y) { mStart.Set(x, y); }

    /** Gets starting position
     * \return Vector Starting position */
    CVector GetStart() { return mStart; }

    /**
     * Gets list of Items in the Game
     * \return List of Items
     */
    std::vector<std::shared_ptr<CItem> > GetItems() { return mItems; }

private:

    /// Scale of the Game dependent on window size
    float mScale = 0.0;

    /// True if Game is currently loading a Level so that the Game does not update
    bool mLoading = false;

    /// An object that describes the current Level
    CLevel mLevel;

    /// An object that describes the Scoreboard
    CScoreboard mScoreboard;

    /// The player-controlled Gnome object
    std::shared_ptr<CGnome> mGnome;

    /// The Items contained in our Game
    std::vector<std::shared_ptr<CItem> > mItems;

    /// The Items to remove in the next update
    std::vector<std::shared_ptr<CItem> > mDelete;

    /// In Game starting point
    CVector mStart;

};