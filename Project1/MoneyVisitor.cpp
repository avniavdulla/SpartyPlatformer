/**
 * \file MoneyVisitor.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"

#include "MoneyVisitor.h"
#include "Money.h"

 /** Visit a Money Item
 * \param money Money we are visiting */
void CMoneyVisitor::VisitMoney(CMoney* money)
{
    money->IncreaseTuition();
}