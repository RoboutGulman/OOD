#include "stdafx.h"

#include "WeatherData.h"

WeatherData::WeatherData()
	: m_temperature(0.0)
	, m_humidity(0.0)
	, m_pressure(760.0)
{
}

double WeatherData::GetTemperature() const
{
	return m_temperature;
}

double WeatherData::GetHumidity() const
{
	return m_humidity;
}

double WeatherData::GetPressure() const
{
	return m_pressure;
}

void WeatherData::MeasurementsChanged()
{
	NotifyObservers();
}

void WeatherData::SetMeasurements(double temp, double humidity, double pressure)
{
	m_humidity = humidity;
	m_temperature = temp;
	m_pressure = pressure;

	MeasurementsChanged();
}

WeatherInfo WeatherData::GetChangedData() const
{
	WeatherInfo info;
	info.temperature = GetTemperature();
	info.humidity = GetHumidity();
	info.pressure = GetPressure();
	return info;
}