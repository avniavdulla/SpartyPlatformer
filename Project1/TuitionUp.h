/**
 * \file TuitionUp.h
 *
 * \author Sean Nguyen
 *
 * Class that implements a Tuition Up Item
 */

#pragma once
#include "Collide.h"

class CTuitionUp : public CCollide
{
public:
    CTuitionUp(CLevel* level);

    /// Default constructor (disabled)
    CTuitionUp() = delete;

    /// Copy constructor (disabled)
    CTuitionUp(const CTuitionUp&) = delete;

    ~CTuitionUp();

    virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;
};

