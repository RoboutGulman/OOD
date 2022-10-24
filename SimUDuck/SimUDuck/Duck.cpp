#include "stdafx.h"

#include "Duck.h"
#include "IDanceBehavior.h"
#include "IFlyBehavior.h"
#include "IQuackBehavior.h"

// сначала проверка на null, потом установка в приватные поля
// использовать set..behavior
Duck::Duck(std::unique_ptr<IFlyBehavior> &&flyBehavior, std::unique_ptr<IQuackBehavior> &&quackBehavior,
           std::unique_ptr<IDanceBehavior> &&danceBehavior)

{
    SetDanceBehavior(std::move(danceBehavior));
    SetFlyBehavior(std::move(flyBehavior));
    SetQuackBehavior(std::move(quackBehavior));
}

void Duck::Quack() const
{
    m_quackBehavior->Quack();
}

void Duck::Swim() const
{
    std::cout << "I'm swimming" << std::endl;
}

void Duck::Fly() const
{
    m_flyBehavior->Fly();
}

void Duck::Dance() const
{
    m_danceBehavior->Dance();
}

void Duck::SetDanceBehavior(std::unique_ptr<IDanceBehavior> &&danceBehavior)
{
    assert(danceBehavior);
    m_danceBehavior = std::move(danceBehavior);
}

void Duck::SetFlyBehavior(std::unique_ptr<IFlyBehavior> &&flyBehavior)
{
    assert(flyBehavior);
    m_flyBehavior = std::move(flyBehavior);
}

void Duck::SetQuackBehavior(std::unique_ptr<IQuackBehavior> &&quackBehavior)
{
    assert(quackBehavior);
    m_quackBehavior = std::move(quackBehavior);
}
