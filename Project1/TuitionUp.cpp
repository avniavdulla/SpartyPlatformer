/**
 * \file TutionUp.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"
#include "TuitionUp.h"

using namespace std;
using namespace Gdiplus;

/** 
 * Constructor
 * \param level The level this is a member of
 */
CTuitionUp::CTuitionUp(CLevel* level) : CCollide(level)
{
}

/**
 * Destructor
 */
CTuitionUp::~CTuitionUp()
{
}

/** 
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \returns Pointer to the created node
 */
std::shared_ptr<xmlnode::CXmlNode> CTuitionUp::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CCollide::XmlSave(node);

    // itemNode->SetAttribute(L"type", L"road");

    return itemNode;
}