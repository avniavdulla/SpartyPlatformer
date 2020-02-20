/**
 * \file DeclareBackground.h
 *
 * \author Sean Nguyen
 *
 * Class that represents the Background Declaration
 */

#pragma once

#include "Declaration.h"

class CDeclareBackground : public CDeclaration
{
public:
    CDeclareBackground();

    /// Copy constructor (disabled)
    CDeclareBackground(const CDeclareBackground&) = delete;

    ~CDeclareBackground();
};

