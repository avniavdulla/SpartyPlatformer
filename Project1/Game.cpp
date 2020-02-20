/**
 * \file Game.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"

#include "Game.h"
// #include "Item.h"
// #include "Gnome.h"
#include "Background.h"
#include "Obstacle.h"
#include "Platform.h"
#include "Villain.h"
#include "Declaration.h"
#include "DeclarePlatform.h"

using namespace std;
using namespace Gdiplus;
using namespace xmlnode;

/// Game area height in virtual pixels
const static int Height = 1024;

/**
 * Constructor
 */
CGame::CGame()
{
    mGnome = make_shared<CGnome>(this);
}

/**
 * Draw the Game
 * \param graphics The GDI+ graphics context to draw on
 * \param width Width of the client window
 * \param height Height of the client window
 */
void CGame::OnDraw(Gdiplus::Graphics* graphics, int width, int height)
{
    //
    // Automatic Scaling
    //
    mScale = float(height) / float(Height);
    graphics->ScaleTransform(mScale, mScale);

    // Determine the virtual width
    auto virtualWidth = (float)width / mScale;

    // Compute the amount to scroll in the X dimension
    auto scroll = (float)-mGnome->GetX() + virtualWidth / 2.0f;
    // auto scroll = 0;

    for (auto item : mItems)
    {
        item->Draw(graphics, scroll);
    }

    mGnome->Draw(graphics, scroll);
    mScoreboard.Draw(graphics, 0);
}

/**
 * Handle updates for animation
 * \param elapsed The time since the last update
 */
void CGame::Update(double elapsed)
{
    for (auto item : mItems)
    {
        item->Update(elapsed);
    }

    mGnome->Update(elapsed);
    mScoreboard.Update(elapsed);
}

/**
 * Add an Item to the Game
 * \param item New Item to add
 */
void CGame::Add(std::shared_ptr<CItem> item)
{
    mItems.push_back(item);
}

/**
 * Clear the Game
 */
void CGame::Clear()
{
    mItems.clear();
}


/**
 * Load the Game from a specified Level
 * \param filename File name of the Level
 */
void CGame::Load(const std::wstring& filename)
{
    Clear();
    mLevel.Reset();
    mGnome->Reset();

    try
    {
        // Open the document to read
        shared_ptr<CXmlNode> root = CXmlNode::OpenDocument(filename);

        double width = root->GetAttributeDoubleValue(L"width", 0);
        double height = root->GetAttributeDoubleValue(L"height", 0);
        double x = root->GetAttributeDoubleValue(L"start-x", 0);
        double y = root->GetAttributeDoubleValue(L"start-y", 0);
        mLevel.SetDimensions(width, height);
        mLevel.SetStart(x, y);

        // Once we know it is open, clear the existing data
        Clear();

        shared_ptr<CXmlNode> declare = root->GetChild(0);

        for (auto node : declare->GetChildren())
        {
            XmlDeclaration(node);
        }

        shared_ptr<CXmlNode> items = root->GetChild(1);

        for (auto node : items->GetChildren())
        {
            XmlItem(node);
        }
    }
    catch (CXmlNode::Exception ex)
    {
        AfxMessageBox(ex.Message().c_str());
    }
    
    mLevel.Install(this);
}

/**
 * Handle a declared Item node
 * \param node Pointer to XML node we are handling
 */
void CGame::XmlDeclaration(const std::shared_ptr<CXmlNode>& node)
{
    shared_ptr<CDeclaration> declare;
    wstring id = node->GetAttributeValue(L"id", L"");
    // mItemIds.insert({ id, node });

    wstring name = node->GetName();
    if (name == L"background")
    {
        declare = make_shared<CDeclaration>();
    }
    else if (name == L"platform")
    {
        declare = make_shared<CDeclaration>();
    }

    if (declare != nullptr)
    {
        declare->XmlDeclare(node);
        mDeclarations.insert({ id, declare });
    }
}

/**
 * Handle an Item node
 * \param node Pointer to XML node we are handling
 */
void CGame::XmlItem(const std::shared_ptr<CXmlNode>& node)
{
    // A pointer for the Item we are loading
    shared_ptr<CItem> item;

    // We have an item. What type?
    wstring name = node->GetName();
    if (name == L"background")
    {
        item = make_shared<CBackground>(this);
        /*auto itr = mItemIds.find(node->GetAttributeValue(L"id", L""));
        auto declare = itr->second;*/
        auto itr = mDeclarations.find(node->GetAttributeValue(L"id", L""));
        auto declare = itr->second;
        item->SetDeclaration(declare);
        /*item->XmlDeclare(declare);*/
    }
    else if (name == L"platform")
    {
        item = make_shared<CPlatform>(this);
        auto itr = mDeclarations.find(node->GetAttributeValue(L"id", L""));
        auto declare = itr->second;

        //declare = make_shared<CDeclarePlatform>();
        item->SetDeclaration(declare);

        
        /*item->XmlDeclare(declare);*/
    }

    if (item != nullptr)
    {
        item->XmlLoad(node);
        mLevel.Add(item);
    }
}

/**
 * Detect collisions within the Game
 * \param gnome The player-controlled Gnome
 * \return Item that is colliding with the Gnome
 */
shared_ptr<CItem> CGame::CollisionTest(CGnome* gnome)
{
    for (auto item : mItems)
    {
        if (item->CollisionTest(gnome))
        {
            return item;
        }
    }
    return nullptr;
}