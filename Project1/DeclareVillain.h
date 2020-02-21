/**
 * \file DeclareVillain.h
 *
 * \author Sean Nguyen
 *
 * Class that represents the Tuition Up Declaration
 */


#pragma once

#include "Declare.h"

/**
 * Represents the Villain Declaration
 */
class CDeclareVillain : public CDeclare
{
public:
    CDeclareVillain();

    /// Copy constructor (disabled)
    CDeclareVillain(const CDeclareVillain&) = delete;

    ~CDeclareVillain();

    virtual std::shared_ptr<CItem> XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node, CGame* game) override;
};

