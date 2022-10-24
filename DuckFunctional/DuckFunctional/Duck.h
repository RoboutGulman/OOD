#pragma once

// ��� ���� ����� ������� ���������
// ����� �������� ���������
//����������� ���������� ���������� �� �����
//��� � ���� ��������� �������� ���������� ����������
class Duck
{
  public:
    using Behavior = std::function<void()>;

    Duck(const Behavior &flyBehavior, const Behavior &quackBehavior, const Behavior &danceBehavior);
    // const ������
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
    // �� ������� ������ � ������, ������� callback
    Behavior m_flyBehavior;
    Behavior m_quackBehavior;
    Behavior m_danceBehavior;
    // ���������-������������ ����� ������
};
