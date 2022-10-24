#include "stdafx.h"

#include "StatsDisplay.h"

StatsDisplay::StatsDisplay()
	: m_temperatureStat("temperature")
	, m_pressureStat("pressure")
	, m_humidityStat("humidity")
{
}

void StatsDisplay::Update(const WeatherInfo& data)
{
	m_temperatureStat.Update(data.temperature);
	m_pressureStat.Update(data.pressure);
	m_humidityStat.Update(data.humidity);

}