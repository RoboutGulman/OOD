#pragma once
#include "stdafx.h"

#include "DanceBehavior.h"
#include "Duck.h"
#include "FlyBehavior.h"
#include "QuackBehavior.h"

class MallardDuck : public Duck
{
  public:
    MallardDuck() : Duck(FlyWithCountBehavior(), QuackBehavior(), DanceWaltzBehavior())
    {
    }

    void Display() const override
    {
        std::cout << "I'm mallard duck" << std::endl;
    }
};
