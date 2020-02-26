/**
 * \file DeclareCheckpoint.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"

#include "DeclareCheckpoint.h"
#include "Checkpoint.h"

using namespace std;
using namespace xmlnode;

/**
 * Constructor
 */
CDeclareCheckpoint::CDeclareCheckpoint()
{
}

/**
 *  Destructor
 */
CDeclareCheckpoint::~CDeclareCheckpoint()
{
}

/**
 * Loads attributes for Checkpoints
 *
 * \param node The Xml Node we are loading the Declare from
 * \param game The Game the created Item belongs to
 * \return Item created from the Declare and the node
 */
shared_ptr<CItem> CDeclareCheckpoint::XmlItem(const shared_ptr<CXmlNode>& node, CGame* game)
{
    shared_ptr<CCheckpoint> item = make_shared<CCheckpoint>(game);

    double x = node->GetAttributeDoubleValue(L"x", 0);
    double y = node->GetAttributeDoubleValue(L"y", 0);

    item->SetLocation(x, y);

    item->SetImage(GetImage());

    return item;
}
