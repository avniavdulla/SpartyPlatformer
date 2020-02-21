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
#include "DeclareWall.h"
#include "DeclareMoney.h"
#include "DeclareTuitionUp.h"
#include "DeclareVillain.h"
#include "DeclareDoor.h"

using namespace std;
using namespace xmlnode;


/// Level 0 filename
const wstring Level0File = L"level0.xml";

/// Level 1 filename
const wstring Level1File = L"level1.xml";

/// Level 2 filename
const wstring Level2File = L"level2.xml";

/// Level 3 filename
const wstring Level3File = L"level3.xml";

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
 * Sets the Level number and associated file
 * \param levelNum Level number
 */
void CLevel::SetLevel(int levelNum)
{
    mLevelNum = levelNum;

    switch (mLevelNum)
    {
        case 0: 
            mFile = Level0File;
            break;
        case 1: 
            mFile = Level1File;
            break;
        case 2: 
            mFile = Level2File;
            break;
        case 3: 
            mFile = Level3File;
            break;
        default:
            mLevelNum = 1;
            mFile = Level1File;
            break;
    }
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
    else if (name == L"wall")
    {
        declare = make_shared<CDeclareWall>();
    }
    else if (name == L"money")
    {
        declare = make_shared<CDeclareMoney>();
    }
    else if (name == L"tuition-up")
    {
        declare = make_shared<CDeclareTuitionUp>();
    }
    else if (name == L"villain")
    {
        declare = make_shared<CDeclareVillain>();
    }
    else if (name == L"door")
    {
        declare = make_shared<CDeclareDoor>();
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
    if (itr != mDeclares.end())
    {
        auto declare = itr->second;

        if (declare != nullptr)
        {
            auto item = declare->XmlItem(node, game);
            Add(item);
        }
    }
}
/**
 * Resets a Level
 */
void CLevel::Reset()
{
    mItems.clear();
}