/** 
* \file Gnome.cpp
* \author Avni Avdulla
*/

#include "pch.h"
#include "Gnome.h"
#include "Vector.h"


/// Gravity in virtual pixels per second per second
const double Gravity = 1000.0;

/// Horizontal character speed in pixels per second
const double HorizontalSpeed = 500.00;

const double JumpSpeed = -800;

/// Small value to ensure we do not stay in collision
const double Epsilon = 0.01;


void CGnome::Update(double elapsed)
{
    CItem::Update(elapsed);

    // Gravity
    // Compute a new velocity with gravity added in.
    CVector newV(mVelocity.X(), mVelocity.Y() + Gravity * elapsed);

        // Update position
        CVector newP = GetPos() + newV * elapsed;

    //
    // Try updating the Y location. 
    //
    SetLocation(GetPos().X(), newP.Y());

    auto collided = GetGame()->CollisionTest(this);
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
    SetLocation(newP.X(), GetPos().Y());

    collided = GetGame()->CollisionTest(this);
    if (collided != nullptr)
    {
        if (newV.X() > 0)
        {
            // We are moving to the right, stop at the collision point
            newP.SetX(collided->GetX() - collided->GetWidth() / 2 - GetWidth() / 2 - Epsilon);
        }
        else
        {
            // We are moving to the left, stop at the collision point
            newP.SetX(collided->GetX() + collided->GetWidth() / 2 + GetWidth() / 2 + Epsilon);
        }


        // If we collide, we cancel any velocity
        // in the X direction
        newV.SetX(0);
    }

    // Update the velocity and position
    mVelocity = newV;
    SetLocation(newP.X(), newP.Y());
}