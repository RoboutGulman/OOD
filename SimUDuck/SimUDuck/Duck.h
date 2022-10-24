#pragma once

#include "Duck.h"
#include "IDanceBehavior.h"
#include "IFlyBehavior.h"
#include "IQuackBehavior.h"

class Duck
{
  public:
    Duck(std::unique_ptr<IFlyBehavior> &&flyBehavior, std::unique_ptr<IQuackBehavior> &&quackBehavior,
         std::unique_ptr<IDanceBehavior> &&danceBehavior);
    void Quack() const;
    // const
    void Swim() const;
    void Fly() const;
    void Dance() const;
    void SetFlyBehavior(std::unique_ptr<IFlyBehavior> &&flyBehavior);
    void SetDanceBehavior(std::unique_ptr<IDanceBehavior> &&danceBehavior);
    void SetQuackBehavior(std::unique_ptr<IQuackBehavior> &&quackBehavior);
    virtual void Display() const = 0;
    virtual ~Duck() = default;

  private:
    std::unique_ptr<IFlyBehavior> m_flyBehavior;
    std::unique_ptr<IQuackBehavior> m_quackBehavior;
    std::unique_ptr<IDanceBehavior> m_danceBehavior;
};
