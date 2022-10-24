#pragma once
#include "Statistics.h"
#include "WeatherData.h"

class PressureStatsDisplay : public IObserver<WeatherInfo>
{
  public:
    PressureStatsDisplay(std::ostream &output) : m_pressureStat("pressure"), m_output(output)
    {
    }

  private:
    void Update(const WeatherInfo &data) override
    {
        m_pressureStat.Update(data.pressure);
        m_output << m_pressureStat.GetStatistics();
    }

    std::ostream &m_output;

    Statistics<double> m_pressureStat;
};
