#include "stdafx.h"

#include "Duck.h"


Duck::Duck(const Behavior &flyBehavior, const Behavior &quackBehavior, const Behavior &danceBehavior)
{
    SetDanceBehavior(danceBehavior);
    SetFlyBehavior(flyBehavior);
    SetQuackBehavior(quackBehavior);
}

void Duck::Quack() const
{
    m_quackBehavior();
}

void Duck::Swim() const
{
    std::cout << "I'm swimming" << std::endl;
}

void Duck::Fly() const
{
    m_flyBehavior();
}

void Duck::Dance() const
{
    m_danceBehavior();
}

void Duck::SetFlyBehavior(const Behavior &flyBehavior)
{
    assert(flyBehavior);
    m_flyBehavior = flyBehavior;
}

void Duck::SetDanceBehavior(const Behavior &danceBehavior)
{
    assert(danceBehavior);
    m_danceBehavior = danceBehavior;
}

void Duck::SetQuackBehavior(const Behavior &quackBehavior)
{
    assert(quackBehavior);
    m_quackBehavior = quackBehavior;
}
