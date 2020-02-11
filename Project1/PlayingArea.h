/**
 * \file PlayingArea.h
 *
 * \author Sean Nguyen
 *
 * Class that implements the Playing Area
 */

#pragma once

class CPlayingArea
{
public:
    CPlayingArea();

    /// Default constructor (disabled)
    CPlayingArea() = delete;

    /// Copy constructor (disabled)
    CPlayingArea(const CPlayingArea&) = delete;

    virtual ~CPlayingArea();
};

