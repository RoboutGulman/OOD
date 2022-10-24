#pragma once

#include "stdafx.h"
/*
Шаблонный интерфейс IObserver. Его должен реализовывать класс,
желающий получать уведомления от соответствующего IObservable
Параметром шаблона является тип аргумента,
передаваемого Наблюдателю в метод Update
*/
template <typename T>
class IObserver
{
  public:
    virtual void Update(const T &data) = 0;
    virtual ~IObserver() = default;
};

/*
Шаблонный интерфейс IObservable. Позволяет подписаться и отписаться на
оповещения, а также инициировать рассылку уведомлений зарегистрированным
наблюдателям.
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

// Реализация интерфейса IObservable
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

    //как сделать быстрее, чем полный перебор
    void RemoveObserver(ObserverType &observer) override
    {
        std::erase_if(m_observers, [&](auto &item) { return item.second == &observer; });
    }

  protected:
    // Классы-наследники должны перегрузить данный метод,
    // в котором возвращать информацию об изменениях в объекте
    virtual T GetChangedData() const = 0;

  private:
    using PriorityObserverMultimap = std::multimap<unsigned int, ObserverType *, std::greater<unsigned int>>;
    PriorityObserverMultimap m_observers;
};
