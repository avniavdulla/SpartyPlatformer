/**
 * \file Level.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"

#include "Level.h"
#include "Game.h"

using namespace std;

/**
 * Constructor
 */
CLevel::CLevel()
{
}

/**
 * Destructor
 */
CLevel::~CLevel()
{
}

/**
 * Add an Item to the Level
 * \param item New Item to add
 */
void CLevel::Add(std::shared_ptr<CItem> item)
{
    mItems.push_back(item);
}

/**
 * Loads a Level to a Game
 * \param game Game to load Level into
 */
void CLevel::Install(CGame* game)
{
    for (auto item : mItems)
    {
        game->Add(item);
    }

    game->GetGnome()->SetLocation(mStart.X(), mStart.Y());
}