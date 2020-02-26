/**
 * \file Checkpoint.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"

#include <string>
#include "Checkpoint.h"
#include "CheckpointVisitor.h"
#include "Game.h"

using namespace std;
using namespace Gdiplus;

/// Collision distance for the Checkpoint in pixels
const double CollisionDistance = 20;

/// Text speed in pixels per second
const double Speed = 800.0;

/// Growth rate of Tuition Up text
const double TextGrow = 40.0;

/// Offset for Out of Bounds
const double OutOfBounds = 100;

/**
 * Constructor
 * \param game The Game this Checkpoint is a member of
 */
CCheckpoint::CCheckpoint(CGame* game) : CItem(game)
{
}

/**
 *  Destructor
 */
CCheckpoint::~CCheckpoint()
{
}

/**
 * Draw the Checkpoint
 *
 * \param graphics The graphics context to draw on
 * \param scroll The scroll offset
 * \return Void
 */
void CCheckpoint::Draw(Gdiplus::Graphics* graphics, float scroll)
{
    if (GetImage() != nullptr)
    {
        double width = GetWidth();
        double height = GetHeight();

        if (!mSet)
        {
            graphics->DrawImage(GetImage().get(),
                float(GetX() - width / 2) + (float)scroll, float(GetY() - height / 2),
                (float)width, (float)height);
        }
        else
        {
            graphics->DrawImage(GetImage().get(),
                float(GetX() - width / 2) + (float)scroll, float(GetY() - height / 2),
                (float)width, (float)height);

            FontFamily fontFamily(L"Arial");
            Gdiplus::Font font(&fontFamily, mTextSize, FontStyleBold);

            StringFormat stringFormat = new StringFormat();
            stringFormat.SetAlignment(StringAlignmentCenter);

            SolidBrush green(Color(79, 160, 66));
            wstring valueLabel = L"Checkpoint Set!";

            graphics->DrawString(valueLabel.c_str(), -1, &font,
                PointF(GetX() + (float)scroll, GetY() - mFly),
                &stringFormat, &green);
        }
    }
}

/**
 * Handle updates in time of the Checkpoint
 * This is called before we draw and allows us to
 * move the Money.
 * \param elapsed Time elapsed since the class call
 */
void CCheckpoint::Update(double elapsed)
{
    if (mSet)
    {
        if (GetY() - mFly >= -OutOfBounds)
        {
            mFly += Speed * elapsed;
            mTextSize += TextGrow * elapsed;
        }
    }
}

/**
 * Tests if any other item is colliding with it
 * \param item Item testing for a collision
 * \return false Gnome can pass through Checkpoint
 */
bool CCheckpoint::CollisionTest(CItem* item)
{
    if (!mSet)
    {
        // Collision for door is different
        double dx = item->GetX() - GetX();
        double dy = item->GetY() - GetY();
        double distance = sqrt(dx * dx + dy * dy);
        if (distance < CollisionDistance)
        {
            CCheckpointVisitor visitor;
            GetGame()->Accept(&visitor);
            GetGame()->SetStart(GetX(), GetY());
            mSet = true;
        }
    }
    return false;
}