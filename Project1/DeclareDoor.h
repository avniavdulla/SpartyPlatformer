/**
 * \file DeclareDoor.h
 *
 * \author Sean Nguyen
 *
 * Class that represents the Door Declaration
 */

#pragma once

#include "Declare.h"

 /**
  * Represents the Door Declaration
  */
class CDeclareDoor : public CDeclare
{
public:
    CDeclareDoor();

    /// Copy constructor (disabled)
    CDeclareDoor(const CDeclareDoor&) = delete;

    ~CDeclareDoor();

    virtual std::shared_ptr<CItem> XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node, CGame* game) override;
};
