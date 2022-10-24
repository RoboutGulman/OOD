#pragma once
template <typename T>
class Statistics
{
  public:
    Statistics(const std::string &name = "%EMPTY_VAL_NAME%")
        : m_min(std::numeric_limits<T>::infinity()), m_max(-std::numeric_limits<T>::infinity()), m_accumulated(0.0),
          m_count(0), m_name(name)
    {
    }

    void Update(const T &newValue)
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
