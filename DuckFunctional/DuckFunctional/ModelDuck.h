#pragma once
#include "stdafx.h"

#include "DanceBehavior.h"
#include "Duck.h"
#include "FlyBehavior.h"
#include "QuackBehavior.h"

class ModelDuck : public Duck
{
  public:
    ModelDuck() : Duck(FlyNoWayBehavior(), QuackBehavior(), DanceNoWayBehavior())
    {
    }

    void Display() const override
    {
        std::cout << "I'm model duck" << std::endl;
    }
};
