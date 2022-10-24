#include "stdafx.h"

#include "StatsDisplay.h"

StatsDisplay::StatsDisplay()
	: m_temperatureStat("temperature")
	, m_pressureStat("pressure")
	, m_humidityStat("humidity")
	, m_windSpeedStat("wind speed")
{
}

void StatsDisplay::Update(const WeatherInfo& data)
{
	m_temperatureStat.Update(data.temperature);
	m_pressureStat.Update(data.pressure);
	m_humidityStat.Update(data.humidity);
	m_windSpeedStat.Update(data.windInfo.windSpeed);
	m_windAngleStat.Update(data.windInfo.windAngle, data.windInfo.windSpeed);

	std::cout << m_temperatureStat << m_pressureStat << m_humidityStat << m_windSpeedStat << m_windAngleStat;
}
