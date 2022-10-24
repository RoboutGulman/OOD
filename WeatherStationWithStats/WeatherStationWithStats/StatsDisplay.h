#pragma once
#include "WeatherData.h"
#include "Statistics.h"

class StatsDisplay : public IObserver<WeatherInfo> {
public:
    StatsDisplay();

private:
    void Update(const WeatherInfo& data) override;

    Statistics<double> m_temperatureStat;
    Statistics<double> m_pressureStat;
    Statistics<double> m_humidityStat;
};
