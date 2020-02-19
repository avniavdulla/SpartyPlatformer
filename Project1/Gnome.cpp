/**
 * \file Gnome.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"
#include <string>
#include "Gnome.h"
#include "Game.h"

using namespace std;

/// Gnome filename
const wstring GnomeImage = L"gnome.png";

/// Gnome Walk Left 1 filename
const wstring GnomeLeft1Image = L"gnome-walk-left-1.png";

/// Gnome Walk Left 2 filename
const wstring GnomeLeft2Image = L"gnome-walk-left-2.png";

/// Gnome Walk Right 1 filename
const wstring GnomeRight1Image = L"gnome-walk-right-1.png";

/// Gnome Walk Right 2 filename
const wstring GnomeRight2Image = L"gnome-walk-right-2.png";

/// Gravity in virtual pixels per second per second
const double Gravity = 1000.0;

/// Horizontal character speed in pixels per second
const double HorizontalSpeed = 500.00;

/// Vertical character speed in pixels per second
const double JumpSpeed = -800;

/// Small value to ensure we do not stay in collision
const double Epsilon = 0.01;

 /**
  * Constructor
  * \param level The Level this Gnome is a member of
  */
CGnome::CGnome(CGame* game) : CItem(game)
{
}

/**
 *  Destructor
 */
CGnome::~CGnome()
{
}

/**
 * Handle updates in time of the Gnome
 * This is called before we draw and allows us to
 * move the Gnome. We add our speed times the amount
 * of time that has elapsed.
 *
 * \param elapsed Time elapsed since the class call
 */
void CGnome::Update(double elapsed)
{
    CItem::Update(elapsed);

    // Gravity
    // Compute a new velocity with gravity added in.
    CVector newVelocity(mVelocity.X(), mVelocity.Y() + Gravity * elapsed);

    // Update position
    // CVector newPos =  GetLocation() + newVelocity * elapsed;
    CVector newPos = GetLocation();
    //
    // Try updating the Y location. 
    //
    SetLocation(GetX(), newPos.Y());

    //auto collided = GetGame()->CollisionTest(this);
    //if (collided != nullptr)
    //{
    //    if (newVelocity.Y() > 0)
    //    {
    //        // We are falling, stop at the collision point
    //        newPos.SetY(collided->GetY() - collided->GetHeight() / 2 - GetHeight() / 2 - Epsilon);
    //    }
    //    else
    //    {
    //        // We are rising, stop at the collision point
    //        newPos.SetY(collided->GetY() + collided->GetHeight() / 2 + GetHeight() / 2 + Epsilon);

    //    }

    //    // If we collide, we cancel any velocity
    //    // in the Y direction
    //    newVelocity.SetY(0);
    //}

    // 
    // Try updating the X location
    //
    SetLocation(newPos.X(), GetY());

    /*auto collideX = GetGame()->CollisionTest(this);
    if (collideX != nullptr)
    {
        if (newVelocity.X() > 0)
        {
            // We are moving to the right, stop at the collision point
            newPos.SetX(collideX->GetX() - collideX->GetWidth() / 2 - GetWidth() / 2 - Epsilon);
        }
        else
        {
            // We are moving to the left, stop at the collision point
            newPos.SetX(collideX->GetX() + collideX->GetWidth() / 2 + GetWidth() / 2 + Epsilon);
        }


        // If we collide, we cancel any velocity
        // in the X direction
        newVelocity.SetX(0);
    }*/

    mWalk += elapsed;

    if (mLeft || mRight)
    {
        newVelocity.SetX(HorizontalSpeed);
    }
    else
    {
        newVelocity.SetX(0);
    }

    if (mLeft) 
    {
        if (mWalk >= 0.4) 
        {
            CItem::SetImage(GnomeLeft1Image);
            mWalk = 0;
        }
        else if (mWalk >= 0.2)
        {
            CItem::SetImage(GnomeLeft2Image);
        }
        else 
        {
            CItem::SetImage(GnomeLeft1Image);
        }
        newPos.SetX(GetX() - newVelocity.X() * elapsed);
    }
    else if (mRight) 
    {
        if (mWalk >= 0.4)
        {
            CItem::SetImage(GnomeRight1Image);
            mWalk = 0;
        }
        else if (mWalk >= 0.2)
        {
            CItem::SetImage(GnomeRight2Image);
        }
        else
        {
            CItem::SetImage(GnomeRight1Image);
        }
        newPos.SetX(GetX() + newVelocity.X() * elapsed);
    }
    else
    {
        CItem::SetImage(GnomeImage);
    }
    

    // Update the velocity and position
    mVelocity = newVelocity;
    SetLocation(newPos.X(), newPos.Y());
}

void CGnome::Reset()
{
    CItem::SetImage(GnomeImage);
    mLeft = false;
    mRight = false;
    mVelocity.Set(0, 0);
}