#pragma once
#include "stdafx.h"

#include "DanceMinuet.h"
#include "Duck.h"
#include "FlyWithWings.h"
#include "QuackBehavior.h"

class RedheadDuck : public Duck
{
  public:
    RedheadDuck()
        : Duck(std::make_unique<FlyWithWings>(), std::make_unique<QuackBehavior>(), std::make_unique<DanceMinuet>())
    {
    }
    void Display() const override
    {
        std::cout << "I'm redhead duck" << std::endl;
    }
};
