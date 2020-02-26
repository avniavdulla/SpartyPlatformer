/**
 * \file Wall.cpp
 *
 * \author Sean Nguyen
 */


#include "pch.h"

#include <string>
#include "Wall.h"

using namespace std;
using namespace Gdiplus;

/**
 * Constructor
 * \param game Game this Wall is a member of
 */
CWall::CWall(CGame* game) : CObstacle(game)
{
}

/**
 *  Destructor
 */
CWall::~CWall()
{
}

/**
 * Draw our Wall
 *
 * \param graphics The graphics context to draw on
 * \param scroll The scroll offset
 * \return Void
 */
void CWall::Draw(Gdiplus::Graphics* graphics, float scroll)
{
    double width = CItem::GetWidth();
    double height = CItem::GetHeight();
    double offset = (CObstacle::GetHeight() - height) / 2;

    for (int i = -offset; i <= offset; i += height)
    {
        graphics->DrawImage(GetImage().get(),
            float(GetX() - width / 2) + (float)scroll, float(GetY() - height / 2) - i,
            (float)width, (float)height + 1);
    }
}