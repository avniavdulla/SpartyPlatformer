/**
 * \file MoneyVisitor.h
 *
 * \author Sean Nguyen
 *
 * Class that visits Money
 */

#pragma once

#include "ItemVisitor.h"

/**
 * Class to visit Money
 */
class CMoneyVisitor : public CItemVisitor
{
public:
    virtual void VisitMoney(CMoney* money) override;
};

