#pragma once

#include "stdafx.h"
/*
��������� ��������� IObserver. ��� ������ ������������� �����,
�������� �������� ����������� �� ���������������� IObservable
���������� ������� �������� ��� ���������,
������������� ����������� � ����� Update
*/
template <typename T>
class IObserver
{
  public:
    virtual void Update(const T &data) = 0;
    virtual ~IObserver() = default;
};

/*
��������� ��������� IObservable. ��������� ����������� � ���������� ��
����������, � ����� ������������ �������� ����������� ������������������
������������.
*/
template <typename T>
class IObservable
{
  public:
    virtual ~IObservable() = default;
    virtual void RegisterObserver(IObserver<T> &observer, unsigned int priority) = 0;
    virtual void NotifyObservers() = 0;
    virtual void RemoveObserver(IObserver<T> &observer) = 0;
};

// ���������� ���������� IObservable
template <typename T>
class Observable : public IObservable<T>
{
  public:
    typedef IObserver<T> ObserverType;

    void RegisterObserver(ObserverType &observer, unsigned int priority) override
    {
        RemoveObserver(observer);
        m_observers.emplace(priority, &observer);
    }

    void NotifyObservers() override
    {
        T data = GetChangedData();
        for (auto &[priority, observer] : m_observers)
        {
            observer->Update(data);
        }
    }

    //��� ������� �������, ��� ������ �������
    void RemoveObserver(ObserverType &observer) override
    {
        std::erase_if(m_observers, [&](auto &item) { return item.second == &observer; });
    }

  protected:
    // ������-���������� ������ ����������� ������ �����,
    // � ������� ���������� ���������� �� ���������� � �������
    virtual T GetChangedData() const = 0;

  private:
    using PriorityObserverMultimap = std::multimap<unsigned int, ObserverType *, std::greater<unsigned int>>;
    PriorityObserverMultimap m_observers;
};
