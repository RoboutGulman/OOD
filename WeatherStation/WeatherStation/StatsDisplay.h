#pragma once
#include "WeatherData.h"

class StatsDisplay : public IObserver<WeatherInfo> {
public:
    StatsDisplay();

private:
    void Update(const WeatherInfo& data) override;

    double m_minTemperature;
    double m_maxTemperature;
    double m_accTemperature;
    unsigned m_countAcc;
};
