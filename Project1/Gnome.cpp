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

    // Gravity
    // Compute a new velocity with gravity added in.
    CVector newV(mVelocity.X(), mVelocity.Y() + Gravity * elapsed);
    //CVector newV(mVelocity.X(), 0);

    // Update position
    CVector newP = GetLocation() + newV * elapsed;

    //
    // Try updating the Y location. 
    //
    SetLocation(GetX(), newP.Y());
    int direction = 0; //means checkling collision in vertical direction

    auto collided = GetGame()->CollisionTest(this, direction);
    if (collided != nullptr)
    {
        if (newV.Y() > 0)
        {
            // We are falling, stop at the collision point
            newP.SetY(collided->GetY() - collided->GetHeight() / 2 - GetHeight() / 2 - Epsilon);
        }
        else
        {
            // We are rising, stop at the collision point
            newP.SetY(collided->GetY() + collided->GetHeight() / 2 + GetHeight() / 2 + Epsilon);

        }

        // If we collide, we cancel any velocity
        // in the Y direction
        newV.SetY(0);
    }

    // 
    // Try updating the X location
    //
    SetLocation(newP.X(), GetY());
    if (mLeft) 
    {
        newV.SetX(-HorizontalSpeed);
    }
    else if (mRight)
    {
        newV.SetX(HorizontalSpeed);
    }
    else
    {
        newV.SetX(0);
    }

    mWalk += elapsed;
    // walking left, swaps images for walking left if walking on platform
    if (mLeft && mVelocity.Y() == 0)
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

    }
    // walking right, swaps images for walking right if walking on platform
    else if (mRight && mVelocity.Y() == 0)
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
    } 
    // mid air going left
    else if (mLeft && mVelocity.Y() != 0)
    {
        CItem::SetImage(GnomeLeft1Image);
    }

    // mid air going left
    else if (mRight && mVelocity.Y() != 0)
    {
        CItem::SetImage(GnomeRight1Image);
    }

    else if (mJump) 
    {
        if (mVelocity.Y() == 0) {
            newV.SetY(JumpSpeed);
        }
        
        mJump = false;
    }

    // either stopped or mid air
    else
    {
        CItem::SetImage(GnomeImage);
    }


    //collided = GetGame()->CollisionTest(this, 0);
    //if (collided != nullptr)
    //{
    //    if (newV.X() > 0)
    //    {
    //        // we are moving to the right, stop at the collision point
    //        newP.SetX(collided->GetX() - collided->GetWidth() / 2 - GetWidth() / 2 - Epsilon);
    //    }
    //    else
    //    {
    //        // we are moving to the left, stop at the collision point
    //        newP.SetX(collided->GetX() + collided->GetWidth() / 2 + GetWidth() / 2 + Epsilon);
    //    }


    //    // if we collide, we cancel any velocity
    //    // in the x direction
    //    newV.SetX(0);
    //}

    // Update the velocity and position
    mVelocity = newV;
    SetLocation(newP.X(), newP.Y());
 
}



void CGnome::Reset()
{
    CItem::SetImage(GnomeImage);
    mLeft = false;
    mRight = false;
    mJump = false;
    mVelocity.Set(0, 0);
}

