/**
 * \file Level.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"

#include "Level.h"
#include "Game.h"
#include "Declare.h"
#include "DeclareBackground.h"
#include "DeclarePlatform.h"

using namespace std;
using namespace xmlnode;

/**
 * Constructor
 */
CLevel::CLevel()
{
}

/**
 * Destructor
 */
CLevel::~CLevel()
{
}

/**
 * Add an Item to the Level
 * \param item New Item to add
 */
void CLevel::Add(std::shared_ptr<CItem> item)
{
    mItems.push_back(item);
}

/**
 * Loads a Level to a Game
 * \param game Game to load Level into
 */
void CLevel::Install(CGame* game)
{

    try
    {
        // Open the document to read
        shared_ptr<CXmlNode> root = CXmlNode::OpenDocument(mFile);

        double width = root->GetAttributeDoubleValue(L"width", 0);
        double height = root->GetAttributeDoubleValue(L"height", 0);
        double x = root->GetAttributeDoubleValue(L"start-x", 0);
        double y = root->GetAttributeDoubleValue(L"start-y", 0);
        SetDimensions(width, height);
        SetStart(x, y);

        // Once we know it is open, clear the existing data
        Reset();

        shared_ptr<CXmlNode> declare = root->GetChild(0);

        for (auto node : declare->GetChildren())
        {
            XmlDeclare(node);
        }

        shared_ptr<CXmlNode> items = root->GetChild(1);

        for (auto node : items->GetChildren())
        {
            XmlItem(node, game);
        }
    }
    catch (CXmlNode::Exception ex)
    {
        AfxMessageBox(ex.Message().c_str());
    }

    for (auto item : mItems)
    {
        game->Add(item);
    }

    game->GetGnome()->Reset(mStart);
}

/**
 * Handle a Declare node
 * \param node Pointer to XML node we are handling
 */
void CLevel::XmlDeclare(const shared_ptr<CXmlNode>& node)
{
    shared_ptr<CDeclare> declare;
    wstring id = node->GetAttributeValue(L"id", L"");

    wstring name = node->GetName();
    if (name == L"background")
    {
        declare = make_shared<CDeclareBackground>();
    }
    else if (name == L"platform")
    {
        declare = make_shared<CDeclarePlatform>();
    }

    if (declare != nullptr)
    {
        declare->XmlDeclare(node);
        mDeclares.insert({ id, declare });
    }
}

/**
 * Handle an Item node
 * \param node Pointer to XML node we are handling
 */
void CLevel::XmlItem(const shared_ptr<CXmlNode>& node, CGame* game)
{
    wstring id = node->GetAttributeValue(L"id", L"");
    auto itr = mDeclares.find(node->GetAttributeValue(L"id", L""));
    auto declare = itr->second;

    if (declare != nullptr)
    {
        auto item = declare->XmlItem(node, game);
        Add(item);
    }
}
/**
 * Resets a Level
 */
void CLevel::Reset()
{
    mItems.clear();
}