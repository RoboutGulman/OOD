#pragma once
#include "stdafx.h"

#include "IDanceBehavior.h"

class DanceMinuet : public IDanceBehavior
{
  public:
    void Dance() const override
    {
        std::cout << "I'm dancing minuet!!" << std::endl;
    }
};
