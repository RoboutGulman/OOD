#include "stdafx.h"

#include "Display.h"

Display::Display(std::ostream &output, IObservable<WeatherInfo> *weatherInside,
                 IObservable<WeatherInfo> *weatherOutside)
    : m_weatherInside(weatherInside), m_weatherOutside(weatherOutside), m_output(output)
{
    m_weatherInside->RegisterObserver(*this);
    m_weatherOutside->RegisterObserver(*this);
}

void Display::Update(const WeatherInfo &data, IObservable<WeatherInfo> &updateInitiator)
{
    m_output << (&updateInitiator == m_weatherInside
                     ? "weather inside"
                     : (&updateInitiator == m_weatherOutside ? "weather outside" : "unknown source"))
             << ":\n";
    m_output << "Current Temp " << data.temperature << '\n';
    m_output << "Current Hum " << data.humidity << '\n';
    m_output << "Current Pressure " << data.pressure << '\n';
    m_output << "----------------" << '\n';
}
