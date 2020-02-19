/**
 * \file Obstacle.cpp
 *
 * \author Sean Nguyen
 */


#include "pch.h"
#include "Obstacle.h"

 /**
  * Constructor
  * \param level The Level this Obstacle is a member of
  * \param filename Filename for the image we use
  */
CObstacle::CObstacle(CLevel* level, const std::wstring& filename) :
    CItem(level)
{
}

/**
 * Draw our Item
 * \param graphics The graphics context to draw on
 */
void CObstacle::Draw(Gdiplus::Graphics* graphics, int scroll)
{
}