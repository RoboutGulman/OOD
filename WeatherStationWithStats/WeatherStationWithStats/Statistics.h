#pragma once
template <typename T>
class Statistics {
public:
    Statistics(const std::string& name)
        : m_min(std::numeric_limits<T>::infinity())
        , m_max(-std::numeric_limits<T>::infinity())
        , m_accumulated(0.0)
        , m_count(0)
        , m_name(name)
    {
    }

    void Update(const T& newValue)
    {
        m_min = std::min(m_min, newValue);
        m_max = std::max(m_max, newValue);

        m_accumulated += newValue;

        ++m_count;

        std::cout << "Max " << m_name << ' ' << std::to_string(m_max) << std::endl;
        std::cout << "Min " << m_name << ' ' << std::to_string(m_min) << std::endl;
        std::cout << "Average " << m_name << ' ' << std::to_string((m_accumulated / m_count)) << std::endl;
        std::cout << "----------------" << std::endl;
    }

private:
    std::string m_name;
    T m_min;
    T m_max;
    T m_accumulated;
    int m_count;
};


constexpr auto MAX_ANGLE = 360;
constexpr auto MAX_ANGLE_2 = 180;

class WindAngleStatisticHolder
{
  public:
    void TakeNextValue(const double &nextVal) noexcept
    {
        m_sumOfSin = m_sumOfSin + std::sin(ToRadians(nextVal));
        m_sumOfCos = m_sumOfCos + std::cos(ToRadians(nextVal));

        auto x = ToDegrees(std::atan2(m_sumOfSin, m_sumOfCos)) + MAX_ANGLE;
        m_average = std::fmod(x, MAX_ANGLE);
    }

    double GetAverage() const noexcept
    {
        return m_average;
    }

  private:
    double ToRadians(double degrees) const
    {
        return M_PI * degrees / MAX_ANGLE_2;
    }

    double ToDegrees(double radians) const
    {
        return MAX_ANGLE_2 * radians / M_PI;
    }

    double m_sumOfSin = 0;
    double m_sumOfCos = 0;
    double m_average = 0;
};
