/**
 * \file Door.h
 *
 * \author Sean Nguyen
 *
 * Class that implements a Door Item
 */

#pragma once
#include "Item.h"

class CDoor : public CItem
{
public:
    CDoor(CLevel* level);

    /// Default constructor (disabled)
    CDoor() = delete;

    /// Copy constructor (disabled)
    CDoor(const CDoor&) = delete;

    ~CDoor();

   // virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

    bool CollisionTest(CItem* item);

private:
    /// Collision distance for the door in pixels
    const double CollisionDistance = 20;
};

