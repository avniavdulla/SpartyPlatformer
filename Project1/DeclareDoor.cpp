/**
 * \file DeclareDoor.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"

#include "DeclareDoor.h"
#include "Door.h"

using namespace std;
using namespace xmlnode;

/**
 * Constructor
 */
CDeclareDoor::CDeclareDoor()
{
}

/**
 *  Destructor
 */
CDeclareDoor::~CDeclareDoor()
{
}

/**
 * Loads attributes for Doors
 *
 * \param node The Xml Node we are loading the Declare from
 * \param game The Game the created Item belongs to
 * \return Item created from the Declare and the node
 */
shared_ptr<CItem> CDeclareDoor::XmlItem(const shared_ptr<CXmlNode>& node, CGame* game)
{
    shared_ptr<CDoor> item = make_shared<CDoor>(game);

    double x = node->GetAttributeDoubleValue(L"x", 0);
    double y = node->GetAttributeDoubleValue(L"y", 0);

    item->SetLocation(x, y);

    item->SetImage(GetImage());

    return item;
}