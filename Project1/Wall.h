/**
 * \file Wall.h
 *
 * \author Sean Nguyen
 *
 * Represents a Wall
 */

#pragma once

#include "Obstacle.h"

/**
 * Represents a Wall
 */
class CWall : public CObstacle
{
public:
    CWall(CGame* game);

    /// Default constructor (disabled)
    CWall() = delete;

    /// Copy constructor (disabled)
    CWall(const CWall&) = delete;

    ~CWall();

    virtual void Draw(Gdiplus::Graphics* graphics, float scroll) override;

    /** Accept a visitor
     * \param visitor The visitor we accept 
     * \return Void */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitWall(this); }
};