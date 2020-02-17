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

    CLevel* GetLevel() { return mLevel; }

    CGnome* GetGnome() { return mLevel->GetGnome(); }
private:
    /// An object that describes the current Level
    CLevel* mLevel;

    /// An object that describes the Scoreboard
    // CScoreboard* mScoreboard;

    /// Scale of the Game dependent on window size
    float mScale = 0.0;
};