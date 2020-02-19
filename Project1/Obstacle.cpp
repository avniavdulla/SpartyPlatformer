/**
 * \file Obstacle.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"

#include "Obstacle.h"

/**
 * Constructor
 * \param game The Game this Obstacle is a member of
 */
CObstacle::CObstacle(CGame* game) : CItem(game)
{
}

/**
 * Destructor
 */
CObstacle::~CObstacle()
{
}

/**
 * Load the attributes for an item node.
 * \param node The Xml node we are loading the item from
 */
void CObstacle::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    CItem::XmlLoad(node);
    mWidth = node->GetAttributeDoubleValue(L"width", 0);
    mHeight = node->GetAttributeDoubleValue(L"height", 0);
}