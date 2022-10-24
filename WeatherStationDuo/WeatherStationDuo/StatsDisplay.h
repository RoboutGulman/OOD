#pragma once
#include "Statistics.h"
#include "WeatherData.h"

class StatsDisplay : public IObserver<WeatherInfo>
{
  public:
    StatsDisplay(Observable<WeatherInfo> *weatherInside, Observable<WeatherInfo> *weatherOutside);

  private:
    void Update(const WeatherInfo &data, IObservable<WeatherInfo> &updateInitiator) override;

    struct WeatherStatistic
    {
        Statistics<double> m_humidityStat;
        Statistics<double> m_pressureStat;
        Statistics<double> m_temperatureStat;
    };

    void StatsUpdate(WeatherStatistic &stats, const WeatherInfo &data);

    std::map<IObservable<WeatherInfo> *, WeatherStatistic> m_observableToStats;
};
