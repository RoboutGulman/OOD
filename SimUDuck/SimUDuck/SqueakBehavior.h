#pragma once
#include "stdafx.h"

#include "IQuackBehavior.h"

class SqueakBehavior : public IQuackBehavior
{
  public:
    void Quack() const override
    {
        std::cout << "Squeek!!!" << std::endl;
    }
};
