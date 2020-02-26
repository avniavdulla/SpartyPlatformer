/**
 * \file ItemVisitor.h
 *
 * \author Sean Nguyen
 *
 * Tile visitor base class.
 */


#pragma once

// Forward references to all item types
class CBackground;
class CPlatform;
class CWall;
class CMoney;
class CTuitionUp;
class CVillain;
class CDoor;
class CGnome;
class CCheckpoint;

/** Item Visitor base class */
class CItemVisitor
{
public:
    virtual ~CItemVisitor() {}

    /** Visit a Background Item
     * \param background Background we are visiting
     * \return Void
     */
    virtual void VisitBackground(CBackground* background) {}

    /** Visit a Platform Item
     * \param platform Platform we are visiting
     * \return Void
     */
    virtual void VisitPlatform(CPlatform* platform) {}

    /** Visit a Wall Item
     * \param wall Wall we are visiting
     * \return Void
     */
    virtual void VisitWall(CWall* wall) {}

    /** Visit a Money Item
     * \param money Money we are visiting
     * \return Void
     */
    virtual void VisitMoney(CMoney* money) {}

    /** Visit a Tuition Up Item
     * \param tuitionUp Tuition Up we are visiting
     * \return Void
     */
    virtual void VisitTuitionUp(CTuitionUp* tuitionUp) {}

    /** Visit a Villain Item
     * \param villain Villain we are visiting
     * \return Void
     */
    virtual void VisitVillain(CVillain* villain) {}

    /** Visit a Door Item
     * \param door Door we are visiting
     * \return Void
     */
    virtual void VisitDoor(CDoor* door) {}

    /** Visit a Gnome Item
     * \param gnome Gnome we are visiting
     * \return Void
     */
    virtual void VisitGnome(CGnome* gnome) {}

    /** Visit a Checkpoint Item
     * \param checkpoint Checkpoint we are visiting 
     * \return Void
     */
    virtual void VisitCheckpoint(CCheckpoint* checkpoint) {}
};
