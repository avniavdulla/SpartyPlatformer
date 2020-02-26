/**
 * \file DeclareVillain.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"

#include "DeclareVillain.h"
#include "Villain.h"

using namespace std;
using namespace xmlnode;

/**
  * Constructor
  */
CDeclareVillain::CDeclareVillain()
{
}

/**
 *  Destructor
 */
CDeclareVillain::~CDeclareVillain()
{
}

/**
 * Loads attributes for Villains
 *
 * \param node The Xml Node we are loading the Declare from
 * \param game The Game the created Item belongs to
 * \return Item created from the Declare and the node
 */
shared_ptr<CItem> CDeclareVillain::XmlItem(const shared_ptr<CXmlNode>& node, CGame* game)
{
    shared_ptr<CVillain> item = make_shared<CVillain>(game);

    double x = node->GetAttributeDoubleValue(L"x", 0);
    double y = node->GetAttributeDoubleValue(L"y", 0);

    item->SetLocation(x, y);
    item->SetRangeHeight();
    item->SetImage(GetImage());

    return item;
}