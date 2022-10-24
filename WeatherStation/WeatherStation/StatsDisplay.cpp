#include "stdafx.h"

#include "StatsDisplay.h"

StatsDisplay::StatsDisplay()
	: m_minTemperature(std::numeric_limits<double>::infinity())
	, m_maxTemperature(-std::numeric_limits<double>::infinity())
	, m_accTemperature(0.0)
	, m_countAcc(0)
{
}

void StatsDisplay::Update(const WeatherInfo& data)
{
	m_minTemperature = std::min(m_minTemperature, data.temperature);
	m_maxTemperature = std::max(m_maxTemperature, data.temperature);

	m_accTemperature += data.temperature;

	++m_countAcc;

	std::cout << "Max Temp " << m_maxTemperature << std::endl;
	std::cout << "Min Temp " << m_minTemperature << std::endl;
	std::cout << "Average Temp " << (m_accTemperature / m_countAcc) << std::endl;
	std::cout << "----------------" << std::endl;
}