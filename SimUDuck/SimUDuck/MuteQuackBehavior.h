#pragma once
#include "stdafx.h"

#include "IQuackBehavior.h"

class MuteQuackBehavior : public IQuackBehavior
{
  public:
    void Quack() const override
    {
    }
};
