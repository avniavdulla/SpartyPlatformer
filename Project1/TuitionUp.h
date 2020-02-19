/**
 * \file TuitionUp.h
 *
 * \author Sean Nguyen
 *
 * Class that implements a Tuition Up Item
 */

#pragma once
#include "Item.h"

class CTuitionUp : public CItem
{
public:
    CTuitionUp(CGame* game);

    /// Default constructor (disabled)
    CTuitionUp() = delete;

    /// Copy constructor (disabled)
    CTuitionUp(const CTuitionUp&) = delete;

    ~CTuitionUp();

};

