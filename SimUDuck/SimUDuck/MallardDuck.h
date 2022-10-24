#pragma once
#include "stdafx.h"

#include "DanceWaltz.h"
#include "Duck.h"
#include "FlyWithWings.h"
#include "QuackBehavior.h"

class MallardDuck : public Duck
{
  public:
    MallardDuck()
        : Duck(std::make_unique<FlyWithWings>(), std::make_unique<QuackBehavior>(), std::make_unique<DanceWaltz>())
    {
    }

    void Display() const override
    {
        std::cout << "I'm mallard duck" << std::endl;
    }
};
