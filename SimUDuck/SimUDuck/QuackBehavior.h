#pragma once
#include "stdafx.h"

#include "IQuackBehavior.h"

class QuackBehavior : public IQuackBehavior
{
  public:
    void Quack() const override
    {
        std::cout << "Quack Quack!!!" << std::endl;
    }
};
