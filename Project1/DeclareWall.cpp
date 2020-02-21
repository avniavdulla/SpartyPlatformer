/**
 * \file DeclareWall.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"
#include <string>
#include "DeclareWall.h"
#include "Wall.h"

using namespace std;
using namespace Gdiplus;

/**
 * Constructor
 * \param level Level this Platform is a member of
 */
CDeclareWall::CDeclareWall()
{
}

/**
 *  Destructor
 */
CDeclareWall::~CDeclareWall()
{
}

/**
 * Loads attributes for Walls
 *
 * \param node The Xml Node we are loading the Declare from
 */
shared_ptr<CItem> CDeclareWall::XmlItem(const shared_ptr<CXmlNode>& node, CGame* game)
{
    shared_ptr<CWall> item = make_shared<CWall>(game);

    double x = node->GetAttributeDoubleValue(L"x", 0);
    double y = node->GetAttributeDoubleValue(L"y", 0);
    double width = node->GetAttributeDoubleValue(L"width", 0);
    double height = node->GetAttributeDoubleValue(L"height", 0);

    item->SetLocation(x, y);
    item->SetDimensions(width, height);
    item->SetImage(GetImage());

    return item;
}