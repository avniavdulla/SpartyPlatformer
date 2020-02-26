/**
 * \file DeclareBackground.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"

#include "DeclareBackground.h"
#include "Background.h"

using namespace std;
using namespace xmlnode;

 /**
  * Constructor
  */
CDeclareBackground::CDeclareBackground()
{
}

/**
 *  Destructor
 */
CDeclareBackground::~CDeclareBackground()
{
}

/**
 * Loads attributes for Backgrounds
 *
 * \param node The Xml Node we are loading the Declare from
 * \param game The Game the created Item belongs to
 * \return Item created from the Declare and the node
 */
shared_ptr<CItem> CDeclareBackground::XmlItem(const shared_ptr<CXmlNode>& node, CGame* game)
{
    shared_ptr<CBackground> item = make_shared<CBackground>(game);

    double x = node->GetAttributeDoubleValue(L"x", 0);
    double y = node->GetAttributeDoubleValue(L"y", 0);

    item->SetLocation(x, y);

    item->SetImage(GetImage());

    return item;
}