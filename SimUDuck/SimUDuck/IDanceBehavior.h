#pragma once
class IDanceBehavior
{
  public:
    virtual ~IDanceBehavior(){};
    // const
    virtual void Dance() const = 0;
};
