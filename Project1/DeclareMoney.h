/**
 * \file DeclareMoney.h
 *
 * \author Sean Nguyen
 *
 * Represents a Money Declaration
 */

#pragma once

#include "Declare.h"

/**
 * Represents the Money Declaration
 */
class CDeclareMoney : public CDeclare
{
public:
    CDeclareMoney();

    /// Copy constructor (disabled)
    CDeclareMoney(const CDeclareMoney&) = delete;

    ~CDeclareMoney();

    virtual void XmlDeclare(const std::shared_ptr<xmlnode::CXmlNode>& node);

    virtual std::shared_ptr<CItem> XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node, CGame* game) override;

    /** Get the value for this Money
    * \returns Value of the Money */
    int GetValue() { return mValue; }

private:
    /// The value of the Money
    int mValue = 100;
};

