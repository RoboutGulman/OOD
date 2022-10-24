#pragma once
#include "stdafx.h"

#include "DanceBehavior.h"
#include "Duck.h"
#include "FlyBehavior.h"
#include "QuackBehavior.h"

class DecoyDuck : public Duck
{
  public:
    DecoyDuck() : Duck(FlyNoWayBehavior(), MuteBehavior(), DanceNoWayBehavior())
    {
    }

    void Display() const override
    {
        std::cout << "I'm decoy duck" << std::endl;
    }
};
