#pragma once
#include "stdafx.h"

#include "IFlyBehavior.h"

class FlyWithWings : public IFlyBehavior
{
  public:
    void Fly() const override
    {
        std::cout << "I'm flying with wings!!" << std::endl;
    }
};
