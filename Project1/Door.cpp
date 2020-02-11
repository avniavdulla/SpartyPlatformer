/**
 * \file Door.cpp
 *
 * \author Sean Nguyen
 */


#include "pch.h"
#include "Door.h"

using namespace std;
using namespace Gdiplus;

/**
 * Constructor
 * \param level The level this is a member of
 */
CDoor::CDoor(CLevel* level) : CCollide(level)
{
}

/**
 * Destructor
 */
CDoor::~CDoor()
{
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \returns Pointer to the created node
 */
std::shared_ptr<xmlnode::CXmlNode> CDoor::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CCollide::XmlSave(node);

    // itemNode->SetAttribute(L"type", L"road");

    return itemNode;
}