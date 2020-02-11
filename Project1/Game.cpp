/**
 * \file Game.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"
#include "Game.h"
#include "XmlNode.h"

using namespace std;
using namespace Gdiplus;
using namespace xmlnode;

/**
 * Constructor
 */
CGame::CGame()
{
    mLevel = NULL;
    mScoreboard = NULL;
}

/**
 * Destructor
 */
CGame::~CGame()
{
}

/**
 * Draw the game
 * \param graphics the GDI+ graphics context to draw on
 */
void CGame::OnDraw(Gdiplus::Graphics* graphics)
{
    mLevel->Draw(graphics);
    mScoreboard->Draw(graphics);
}

/**
 * Save the level as an XML file.
 * Open an XML file and stream the level data to it.
 * \param filename The filename of the file to save the level to
 */
void CGame::Save(const std::wstring& filename)
{
    // Create an XML document
    auto root = CXmlNode::CreateDocument(L"xml");

    // Iterate over all items and save them
    /*for (auto item : mItems)
    {
        item->XmlSave(root);
    }*/

    try
    {
        root->Save(filename);
    }
    catch (CXmlNode::Exception ex)
    {
        AfxMessageBox(ex.Message().c_str());
    }
}

/**
 * Load the level from an XML file.
 * Opens the XML file and reads the nodes, creating the level and items as appropriate.
 * \param filename The filename of the file to load the level from.
 */
void CGame::Load(const std::wstring& filename)
{
    try
    {
        // Open the document to read
        shared_ptr<CXmlNode> level = CXmlNode::OpenDocument(filename);

        // Once we know it is open, clear the existing data
        // Clear();

        //
        // Traverse the children of the root
        // node of the XML document in memory!!!!
        //
        for (auto node : level->GetChildren())
        {
            if (node->GetType() == NODE_ELEMENT && node->GetName() == L"item")
            {
                XmlItem(node);
            }
        }
    }
    catch (CXmlNode::Exception ex)
    {
        AfxMessageBox(ex.Message().c_str());
    }
}