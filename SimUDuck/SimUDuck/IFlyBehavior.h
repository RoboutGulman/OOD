#pragma once
class IFlyBehavior
{
  public:
    virtual ~IFlyBehavior(){};
    virtual void Fly() const = 0;
};
