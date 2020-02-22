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
    //If player is dying it triggers the lose state
    // could happen from falling or colliding with villan 
    if (mDying)
    {
        GetGame()->Lose();
        mDying = false;
    }

    // Gravity
    // Compute a new velocity with gravity added in.
    CVector newVelocity(mVelocity.X(), mVelocity.Y() + Gravity * elapsed);

    if ((mLeft && mRight) || (!mLeft && !mRight))
    {
        newVelocity.SetX(0);
    }
    else if (mLeft)
    {
        newVelocity.SetX(-HorizontalSpeed);
    }
    else if (mRight)
    {
        newVelocity.SetX(HorizontalSpeed);
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
            newVelocity.SetY(JumpSpeed);
        }
        mJump = false;
    }
    // either stopped or mid air
    else
    {
        CItem::SetImage(GnomeImage);
    }

    // Update position
    CVector newPos = GetLocation() + newVelocity * elapsed;

    //
    // Try updating the Y location. 
    //
    SetLocation(GetX(), newPos.Y());
    // 
    // Try updating the X location
    //
    SetLocation(newPos.X(), GetY());

    // checks collision while falling 
    auto collided = GetGame()->CollisionTest(this);
    if (collided != nullptr)
    {
        if (newVelocity.Y() > 0 )
        {
            
            // We are falling, stop at the collision point
            newPos.SetY(collided->GetY() - collided->GetHeight() / 2 - GetHeight() / 2 - Epsilon);
            //newVelocity.SetY(0);
        }
        else if (newVelocity.Y() < 0 )
        {
            // We are rising, stop at the collision point
            newPos.SetY(collided->GetY() + collided->GetHeight() / 2 + GetHeight() / 2 + Epsilon);
            //newVelocity.SetY(0);
        }

        // If we collide, we cancel any velocity
        // in the Y direction
        newVelocity.SetY(0);
    }

    
    collided = GetGame()->CollisionTest(this);
    if (collided != nullptr)
    {
        auto itemTop = collided->GetY() - collided->GetHeight() / 2;
        auto ourBottom = GetY() + GetHeight() / 2;
        auto ourTop = GetY() - GetHeight() / 2;

        //makes sure the platform is not below or above gnome
        if (newVelocity.X() > 0 && !(collided->GetY() > ourBottom ) &&  !(collided->GetY() < ourTop)) 
        {
            // We are moving to the right, stop at the collision point 
            newPos.SetX(collided->GetX() - collided->GetWidth() / 2 - GetWidth() / 2 - Epsilon);
            //newVelocity.SetX(0);
        }
        //makes sure the platform is not below or above gnome
        else if (newVelocity.X() < 0 && !(collided->GetY() > ourBottom ) && !(collided->GetY() < ourTop))
        {
            // We are moving to the left, stop at the collision point
            newPos.SetX(collided->GetX() + collided->GetWidth() / 2 + GetWidth() / 2 + Epsilon);
            //newVelocity.SetX(0);
        }

        // If we collide, we cancel any velocity
        // in the X direction
        newVelocity.SetX(0);
    }

    // checks if gnome got reset from dying or hitting door
    // position is set to start of level, and not updated here
    if (mReset)
    {
        mReset = false;
    }
    // if not function is normal
    else
    {
        // Update the velocity and position
        mVelocity = newVelocity;
        SetLocation(newPos.X(), newPos.Y());
    }

    auto ourTop = GetY() - GetHeight() / 2;
    // gnome falling out of the window, therefor dying 
    if (ourTop > GetGame()->GetLevelHeight()) 
    {
        mDying = true;
    }
    
}

void CGnome::Reset(CVector start)
{
    CItem::SetImage(GnomeImage);
    CItem::SetLocation(start);
    mLeft = false;
    mRight = false;
    mJump = false;
    mVelocity.Set(0, 0);
}

