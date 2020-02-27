/**
 * \file Scoreboard.h
 *
 * \author Sean Nguyen
 *
 * Represents the Scoreboard
 */

#pragma once

/**
 * Class that represents the Scoreboard
 */
class CScoreboard
{
public:
    CScoreboard();

    ~CScoreboard();

    void Draw(Gdiplus::Graphics* graphics);

    void Update(double elapsed);

    void Reset();

    /**
     * Increments the score
     * \param value Value to increment score by
     */
    void AddScore(int value) { mScore += value; }

    /**
     * Gets the score
     * \return Current score of the Game
     */
    int GetScore() { return mScore; }

    /**
     * Sets Lose condition
     */
    void Lose() { mLose = true; }

private:
    /// Seconds spent in the Level
    double mSeconds = 0;

    /// Score accumulated in the Level
    int mScore = 0;

    /// True if in Lose condition
    bool mLose = false;
};