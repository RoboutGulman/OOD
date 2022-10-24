#include "stdafx.h"

#include "Observer.h"
#include "StatsDisplay.h"

StatsDisplay::StatsDisplay(Observable<WeatherInfo> *weatherInside, Observable<WeatherInfo> *weatherOutside)
    : m_observableToStats(
          {{weatherInside,
            {Statistics<double>("humidity"), Statistics<double>("pressure"), Statistics<double>("temperature")}},
           {weatherOutside,
            {Statistics<double>("humidity"), Statistics<double>("pressure"), Statistics<double>("temperature")}}})
{
}

void StatsDisplay::StatsUpdate(WeatherStatistic &stats, const WeatherInfo &data)
{
    stats.m_humidityStat.Update(data.humidity);
    stats.m_pressureStat.Update(data.pressure);
    stats.m_temperatureStat.Update(data.temperature);
}

void StatsDisplay::Update(const WeatherInfo &data, IObservable<WeatherInfo> &updateInitiator)
{
    if (m_observableToStats.find(&updateInitiator) != std::end(m_observableToStats))
    {
        StatsUpdate(m_observableToStats[&updateInitiator], data);
    }
}
