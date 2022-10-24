#pragma once
#include "stdafx.h"

#include "IDanceBehavior.h"

class DanceNoWay : public IDanceBehavior
{
  public:
    void Dance() const override
    {
    }
};
