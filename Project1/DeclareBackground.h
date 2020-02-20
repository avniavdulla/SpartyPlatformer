/**
 * \file DeclareBackground.h
 *
 * \author Sean Nguyen
 *
 * Class that represents the Background Declare
 */

#pragma once

#include "Declare.h"

class CDeclareBackground : public CDeclare
{
public:
    CDeclareBackground();

    /// Copy constructor (disabled)
    CDeclareBackground(const CDeclareBackground&) = delete;

    ~CDeclareBackground();

    virtual std::shared_ptr<CItem> XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node, CGame* game) override;
};