/**
 * \file DeclareCheckpoint.h
 *
 * \author Sean Nguyen
 *
 * Class that represents the Checkpoint Declaration
 */

#pragma once

#include "Declare.h"


/**
 * Represents the Checkpoint Declaration
 */
class CDeclareCheckpoint : public CDeclare
{
public:
    CDeclareCheckpoint();

    /// Copy constructor (disabled)
    CDeclareCheckpoint(const CDeclareCheckpoint&) = delete;

    ~CDeclareCheckpoint();

    virtual std::shared_ptr<CItem> XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node, CGame* game) override;
};

