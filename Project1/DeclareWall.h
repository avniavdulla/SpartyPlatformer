/**
 * \file DeclareWall.h
 *
 * \author Sean Nguyen
 *
 * Represents a Wall Declaration
 */

#pragma once

#include "Declare.h"

/**
 * Class that represents a Wall Declaration
 */
class CDeclareWall : public CDeclare
{
public:
    CDeclareWall();

    /// Copy constructor (disabled)
    CDeclareWall(const CDeclareWall&) = delete;

    ~CDeclareWall();

    virtual std::shared_ptr<CItem> XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node, CGame* game) override;
};

