#pragma once
#include "Statistics.h"
#include "WeatherData.h"

class TemperatureStatsDisplay : public IObserver<WeatherInfo>
{
  public:
    TemperatureStatsDisplay(std::ostream &output) : m_temperatureStat("temperature"), m_output(output)
    {
    }

  private:
    void Update(const WeatherInfo &data) override
    {
        m_temperatureStat.Update(data.temperature);
        m_output << m_temperatureStat.GetStatistics();
    }
    std::ostream &m_output;

    Statistics<double> m_temperatureStat;
};
