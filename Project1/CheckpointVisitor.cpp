/**
 * \file CheckpointVisitor.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"

#include "CheckpointVisitor.h"
#include "Checkpoint.h"

 /** Visit a Checkpoint Item
 * \param money Money we are visiting */
void CCheckpointVisitor::VisitCheckpoint(CCheckpoint* checkpoint)
{
    checkpoint->UnsetCheckpoint();
}