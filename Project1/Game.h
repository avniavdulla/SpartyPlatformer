/**
 * \file Game.h
 *
 * \author Sean Nguyen
 *
 * Class that implements the Game
 */

#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Level.h"
#include "PlayingArea.h"
#include "Scoreboard.h"

 /**
  * Implements a game
  */
class CGame
{
public:
    CGame();

    /// Default constructor (disabled)
    CGame() = delete;

    /// Copy constructor (disabled)
    CGame(const CGame&) = delete;

    ~CGame();

    void OnDraw(Gdiplus::Graphics* graphics);

    void Save(const std::wstring& filename);

    void Load(const std::wstring& filename);

private:
    /// Level available to play
    std::unique_ptr<CLevel> mLevel;

    /// Playing Area object for the game
    std::unique_ptr<CPlayingArea> mPlayingArea;

    /// Scoreboard object for the game
    std::unique_ptr<CScoreboard> mScoreboard;
};

