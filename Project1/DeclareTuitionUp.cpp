/**
 * \file DeclareTuitionUp.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"

#include <string>

#include "DeclareTuitionUp.h"
#include "TuitionUp.h"

using namespace std;

/**
 * Constructor
 */
CDeclareTuitionUp::CDeclareTuitionUp()
{
}

/**
 *  Destructor
 */
CDeclareTuitionUp::~CDeclareTuitionUp()
{
}

/**
 * Loads attributes for Platforms
 *
 * \param node The Xml Node we are loading the Declare from
 */
shared_ptr<CItem> CDeclareTuitionUp::XmlItem(const shared_ptr<CXmlNode>& node, CGame* game)
{
    shared_ptr<CTuitionUp> item = make_shared<CTuitionUp>(game);

    double x = node->GetAttributeDoubleValue(L"x", 0);
    double y = node->GetAttributeDoubleValue(L"y", 0);
    double width = node->GetAttributeDoubleValue(L"width", 0);
    double height = node->GetAttributeDoubleValue(L"height", 0);

    item->SetLocation(x, y);
    item->SetImage(GetImage());

    return item;
}