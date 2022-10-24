#pragma once
#include "WeatherData.h"

class Display : public IObserver<WeatherInfo>
{
  public:
    Display(std::ostream &output);

  private:
    void Update(const WeatherInfo &data) override;
    std::ostream &m_output;
};
