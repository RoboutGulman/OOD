#pragma once

// для чего нужен паттерн стратегия
// схема паттерна стратегия
//обозначение реализации интерфейса на схеме
//что в этой программе является семейством алгоритмов
class Duck
{
  public:
    using Behavior = std::function<void()>;

    Duck(const Behavior &flyBehavior, const Behavior &quackBehavior, const Behavior &danceBehavior);
    // const методы
    void Quack() const;
    void Swim() const;
    void Fly() const;
    void Dance() const;
    void SetFlyBehavior(const Behavior &flyBehavior);
    void SetDanceBehavior(const Behavior &danceBehavior);
    void SetQuackBehavior(const Behavior &quackBehavior);
    virtual void Display() const = 0;
    virtual ~Duck() = default;

  private:
    // не хранить данные в классе, сделать callback
    Behavior m_flyBehavior;
    Behavior m_quackBehavior;
    Behavior m_danceBehavior;
    // плаванние-неизменяемая часть класса
};
