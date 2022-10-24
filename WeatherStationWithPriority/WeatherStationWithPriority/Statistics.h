#pragma once
template <typename T>
class Statistics
{
  public:
    Statistics(std::string name)
        : m_min(std::numeric_limits<T>::infinity()), m_max(-std::numeric_limits<T>::infinity()), m_accumulated(0.0), m_count(0),
          m_name(name)
    {
    }

    void Update(const T &nextValue)
    {
        m_min = std::min(m_min, nextValue);
        m_max = std::max(m_max, nextValue);

        m_accumulated += nextValue;

        ++m_count;
    }

    std::string GetStatistics()
    {
        return std::string("Max " + m_name + ' ' + std::to_string(m_max) + '\n' + "Min " + m_name + ' ' +
                           std::to_string(m_min) + '\n' + "Average " + m_name + ' ' +
                           std::to_string((m_accumulated / m_count)) + '\n' + "----------------" + '\n');
    }

  private:
    std::string m_name;
    T m_min;
    T m_max;
    T m_accumulated;
    int m_count;
};
