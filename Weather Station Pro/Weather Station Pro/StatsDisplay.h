#pragma once
#include "Statistics.h"
#include "WeatherData.h"

class StatsDisplay : public IObserver<WeatherInfo>
{
public:
	StatsDisplay();

private:
	void Update(const WeatherInfo& data) override;

	Statistics<double> m_temperatureStat;
	Statistics<double> m_pressureStat;
	Statistics<double> m_humidityStat;
	Statistics<double> m_windSpeedStat;
	WindAngleStatistics m_windAngleStat;
};
