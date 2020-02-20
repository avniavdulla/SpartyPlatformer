/**
 * \file Declare.h
 *
 * \author Sean
 *
 * Base class for any Declaration
 */

#pragma once

#include "XmlNode.h"
#include "Item.h"

using namespace xmlnode;

class CDeclare 
{
public:
    /// The directory where the images are stored
    static const std::wstring ImagesDirectory;

    /// Default constructor (disabled)
    // CDeclare() = delete;

    /// Copy constructor (disabled)
    CDeclare(const CDeclare&) = delete;

    virtual ~CDeclare();

    void SetImage(const std::wstring& file);

    /**  Get the file name for this tile image
     * \returns Filename or blank if none */
    std::wstring GetFile() { return mFile; }

    /** Get the image for this Item
     * \returns Image */
    std::shared_ptr<Gdiplus::Bitmap> GetImage() { return mImage; }

    virtual void XmlDeclare(const std::shared_ptr<xmlnode::CXmlNode>& node);

    /** Creates an Item based on the Declare
     * \param node The Xml Node we are loading the Item from
     */
    virtual std::shared_ptr<CItem> XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node, CGame* game);

protected:
    CDeclare();

private:
    /// The image of this Item
    std::shared_ptr<Gdiplus::Bitmap> mImage;

    /// The file for this Item
    std::wstring mFile;
};
