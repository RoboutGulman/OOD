#pragma once
#include "stdafx.h"

#include "IDanceBehavior.h"

class DanceWaltz : public IDanceBehavior
{
  public:
    void Dance() const override
    {
        std::cout << "I'm dancing waltz!!" << std::endl;
    }
};
