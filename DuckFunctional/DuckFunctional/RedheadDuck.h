#pragma once
#include "stdafx.h"

#include "DanceBehavior.h"
#include "Duck.h"
#include "FlyBehavior.h"
#include "QuackBehavior.h"

class RedheadDuck : public Duck
{
  public:
    RedheadDuck() : Duck(FlyWithCountBehavior(), QuackBehavior(), DanceMinuetBehavior())
    {
    }

    void Display() const override
    {
        std::cout << "I'm redhead duck" << std::endl;
    }
};
