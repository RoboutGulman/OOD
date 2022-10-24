#pragma once
#include "stdafx.h"

#include "DanceBehavior.h"
#include "Duck.h"
#include "FlyBehavior.h"
#include "QuackBehavior.h"

class RubberDuck : public Duck
{
  public:
    RubberDuck() : Duck(FlyNoWayBehavior(), SqueekBehavior(), DanceNoWayBehavior())
    {
    }

    void Display() const override
    {
        std::cout << "I'm rubber duck" << std::endl;
    }
};
