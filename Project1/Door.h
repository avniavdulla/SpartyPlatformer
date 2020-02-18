/**
 * \file Door.h
 *
 * \author Sean Nguyen
 *
 * Class that implements a Door Item
 */

#pragma once
#include "Collide.h"

class CDoor : public CCollide
{
public:
    CDoor(CLevel* level);

    /// Default constructor (disabled)
    CDoor() = delete;

    /// Copy constructor (disabled)
    CDoor(const CDoor&) = delete;

    ~CDoor();

    virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;
};
