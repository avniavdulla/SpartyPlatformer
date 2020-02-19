/**
 * \file Game.h
 *
 * \author Sean Nguyen
 *
 * Class that represents the Game.
 */

#pragma once

#include "Level.h"
#include "Gnome.h"


class CGnome;
class CLevel;

 /**
  * Represents the Game
  */
class CGame
{
public:
    CGame();

    void OnDraw(Gdiplus::Graphics* graphics, int width, int height);


    // void LoadLevel(CLevel* level) { mLevel = level; }

    void Update(double elapsed);

    CLevel* GetLevel() { return CGame::mLevel; }

    CGnome* GetGnome() { return CGame::mGnome; }

    std::shared_ptr<CItem> CollisionTest(CGnome* gnome);


private:
    /// An object that describes the current Level
    CLevel* mLevel;

    /// An object that describes the current level
    CGnome* mGnome;

    /// An object that describes the Scoreboard
    // CScoreboard* mScoreboard;

    /// holds items from level
    std::vector<std::shared_ptr<CItem>> mItems;

    /// Scale of the Game dependent on window size
    float mScale = 0.0;
};