#pragma once
#include "stdafx.h"

#include "DanceNoWay.h"
#include "Duck.h"
#include "FlyNoWay.h"
#include "MuteQuackBehavior.h"

class DecoyDuck : public Duck
{
  public:
    DecoyDuck()
        : Duck(std::make_unique<FlyNoWay>(), std::make_unique<MuteQuackBehavior>(), std::make_unique<DanceNoWay>())
    {
    }

    void Display() const override
    {
        std::cout << "I'm decoy duck" << std::endl;
    }
};
