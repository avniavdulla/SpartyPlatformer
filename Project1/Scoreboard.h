/**
 * \file Scoreboard.h
 *
 * \author Sean Nguyen
 *
 * Represents the Scoreboard
 */

#pragma once

class CScoreboard
{
public:
    CScoreboard();

    ~CScoreboard();

    void Draw(Gdiplus::Graphics* graphics, int scroll);

    void Update(double elapsed);

    void Reset();

    /**
     * Increments the score
     * \param value Value to increment score by
     */
    void AddScore(int value) { mScore += value; }

    void Lose() { mLose = true; }

private:
    /// Seconds spent in the Level
    double mSeconds = 0;

    /// Score accumulated in the Level
    int mScore = 0;

    bool mLose = false;
};