#pragma once
#include "Observer.h"
#include "WeatherData.h"

class Display : public IObserver<WeatherInfo>
{
  public:
    Display(std::ostream &output, IObservable<WeatherInfo> *weatherInside, IObservable<WeatherInfo> *weatherOutside);

  private:
    using ObserverType = IObservable<WeatherInfo> *;

    void Update(const WeatherInfo &data, IObservable<WeatherInfo> &updateInitiator) override;

    // טםעונפויס גלוסעמ observable<WI>
    ObserverType m_weatherInside;
    ObserverType m_weatherOutside;
    std::ostream &m_output;
};
