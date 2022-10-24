#pragma once
#include "Statistics.h"
#include "WeatherData.h"

class HumidityStatsDisplay : public IObserver<WeatherInfo>
{
  public:
    HumidityStatsDisplay(std::ostream &output) : m_humidityStat("humidity"), m_output(output)
    {
    }

  private:
    void Update(const WeatherInfo &data) override
    {
        m_humidityStat.Update(data.humidity);
        m_output << m_humidityStat.GetStatistics();
    }

    std::ostream &m_output;

    Statistics<double> m_humidityStat;
};
