#include "stdafx.h"

#include "Display.h"

Display::Display(std::ostream &output) : m_output(output)
{
}

void Display::Update(const WeatherInfo &data)
{
    m_output << "Current Temp " << data.temperature << std::endl;
    m_output << "Current Hum " << data.humidity << std::endl;
    m_output << "Current Pressure " << data.pressure << std::endl;
    m_output << "----------------" << std::endl;
}
