/**
 * \file CheckpointVisitor.cpp
 *
 * \author Sean Nguyen
 */

#include "pch.h"

#include "CheckpointVisitor.h"
#include "Checkpoint.h"

 /** Visit a Checkpoint Item
  * \param checkpoint Money we are visiting 
  * \return Void
  */
void CCheckpointVisitor::VisitCheckpoint(CCheckpoint* checkpoint)
{
    checkpoint->UnsetCheckpoint();
}