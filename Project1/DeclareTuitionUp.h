/**
 * \file DeclareTuitionUp
 *
 * \author Sean Nguyen
 *
 * Class that represents the Tuition Up Declaration
 */

#pragma once

#include "Declare.h"

/**
 * Represents the Tuition Up Declaration
 */
class CDeclareTuitionUp : public CDeclare
{
public:
    CDeclareTuitionUp();

    /// Copy constructor (disabled)
    CDeclareTuitionUp(const CDeclareTuitionUp&) = delete;

    ~CDeclareTuitionUp();

    virtual std::shared_ptr<CItem> XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node, CGame* game) override;
};

