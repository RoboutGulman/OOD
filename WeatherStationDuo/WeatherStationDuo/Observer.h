#pragma once

#include "stdafx.h"

template <typename T>
class IObservable;
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
    virtual void Update(const T &data, IObservable<T> &updateInitiator) = 0;
    virtual ~IObserver() = default;
};

/*
��������� ��������� IObservable. ��������� ����������� � ���������� �� ����������, � �����
������������ �������� ����������� ������������������ ������������.
*/
template <typename T>
class IObservable
{
  public:
    virtual ~IObservable() = default;
    virtual void RegisterObserver(IObserver<T> &observer) = 0;
    virtual void NotifyObservers() = 0;
    virtual void RemoveObserver(IObserver<T> &observer) = 0;
};


// ����������
template <typename T>
class Observable : public IObservable<T>
{
  public:
    typedef IObserver<T> ObserverType;

    void RegisterObserver(ObserverType &observer) override
    {
        m_observers.insert(&observer);
    }

    void NotifyObservers() override
    {
        T data = GetChangedData();
        for (auto &observer : m_observers)
        {
            observer->Update(data, *this);
        }
    }

    void RemoveObserver(ObserverType &observer) override
    {
        auto findIt = m_observers.find(&observer);
        if (findIt != m_observers.end())
        {
            m_observers.erase(findIt);
        }
    }

  protected:
    // ������-���������� ������ ����������� ������ �����,
    // � ������� ���������� ���������� �� ���������� � �������
    virtual T GetChangedData() const = 0;

  private:
    std::set<ObserverType *> m_observers;
};
