/**
 * \file DeclareMoney.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"

#include <string>

#include "DeclareMoney.h"
#include "Money.h"

using namespace std;

/**
 * Constructor
 */
CDeclareMoney::CDeclareMoney()
{
}

/**
 *  Destructor
 */
CDeclareMoney::~CDeclareMoney()
{
}

/**
 * Load the attributes for an item node
 *
 * \param node The Xml node we are loading the item from
 */
void CDeclareMoney::XmlDeclare(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    CDeclare::XmlDeclare(node);

    mValue = node->GetAttributeIntValue(L"value", 0);
}

/**
 * Loads attributes for Platforms
 *
 * \param node The Xml Node we are loading the Declare from
 */
shared_ptr<CItem> CDeclareMoney::XmlItem(const shared_ptr<CXmlNode>& node, CGame* game)
{
    shared_ptr<CMoney> item = make_shared<CMoney>(game);

    double x = node->GetAttributeDoubleValue(L"x", 0);
    double y = node->GetAttributeDoubleValue(L"y", 0);
    double width = node->GetAttributeDoubleValue(L"width", 0);
    double height = node->GetAttributeDoubleValue(L"height", 0);

    item->SetLocation(x, y);
    item->SetImage(GetImage());
    item->SetValue(mValue);

    return item;
}