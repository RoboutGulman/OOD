#pragma once
#include "stdafx.h"

template <typename T>
class Statistics
{
public:
	Statistics(const std::string& name)
		: m_min(std::numeric_limits<T>::infinity())
		, m_max(-std::numeric_limits<T>::infinity())
		, m_accumulated(0.0)
		, m_name(name)
	{
	}

	void Update(const T& newValue)
	{
		m_min = std::min(m_min, newValue);
		m_max = std::max(m_max, newValue);

		m_accumulated += newValue;

		++m_count;
	}

	T GetMin() const
	{
		return m_min;
	}

	T GetMax() const
	{
		return m_max;
	}

	T GetAverage() const
	{
		return (m_count != 0) ? m_accumulated / m_count : T();
	}

	std::string GetName() const
	{
		return m_name;
	}

private:
	std::string m_name;
	T m_min;
	T m_max;
	T m_accumulated;
	int m_count = 0;
};

template <typename T>
std::ostream& operator<<(std::ostream& stream, Statistics<T> const& stat)
{
	stream << "Max " << stat.GetName() << ' ' << std::to_string(stat.GetMax()) << std::endl;
	stream << "Min " << stat.GetName() << ' ' << std::to_string(stat.GetMin()) << std::endl;
	stream << "Average " << stat.GetName() << ' ' << std::to_string(stat.GetAverage()) << std::endl;
	stream << "----------------" << std::endl;

	return stream;
}

constexpr auto DEGREES_IN_CIRCLE = 360;
constexpr auto DEGREES_IN_SEMICIRCLE = 180;

class WindAngleStatistics
{
public:
	// доп. функция для возвращения угла
	void Update(const double& newAngle, const double& newSpeed) noexcept
	{
		m_sumOfSin += newSpeed * std::sin(ToRadians(newAngle));
		m_sumOfCos += newSpeed * std::cos(ToRadians(newAngle));

		m_average = ToDegrees(std::atan2(m_sumOfSin, m_sumOfCos));
	}

	double GetAverage() const
	{
		return m_average;
	}

private:
	double ToRadians(double degrees) const
	{
		return M_PI * degrees / DEGREES_IN_SEMICIRCLE;
	}

	double ToDegrees(double radians) const
	{
		return DEGREES_IN_SEMICIRCLE * radians / M_PI;
	}

	double m_sumOfSin = 0;
	double m_sumOfCos = 0;
	double m_average = 0;
	int m_count = 0;
};

std::ostream& operator<<(std::ostream& stream, WindAngleStatistics const& stat);
