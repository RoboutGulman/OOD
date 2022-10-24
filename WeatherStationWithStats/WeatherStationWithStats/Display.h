#pragma once
#include "WeatherData.h"

class Display : public IObserver<WeatherInfo>
{
    void Update(const WeatherInfo &data) override
    {
        std::cout << "Current Temp " << data.temperature << std::endl;
        std::cout << "Current Hum " << data.humidity << std::endl;
        std::cout << "Current Pressure " << data.pressure << std::endl;
        std::cout << "----------------" << std::endl;
    }
};
