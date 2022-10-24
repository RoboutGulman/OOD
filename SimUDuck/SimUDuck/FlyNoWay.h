#pragma once
#include "stdafx.h"

#include "IFlyBehavior.h"

class FlyNoWay : public IFlyBehavior
{
  public:
    void Fly() const override
    {
    }
};
