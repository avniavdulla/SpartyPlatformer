/**
 * \file CheckpointVisitor.h
 *
 * \author Sean Nguyen
 *
 * Class that visits Checkpoints
 */

#pragma once

#include "ItemVisitor.h"

 /**
  * Class to visit Checkpoints
  */
class CCheckpointVisitor : public CItemVisitor
{
public:
    virtual void VisitCheckpoint(CCheckpoint* checkpoint) override;
};
