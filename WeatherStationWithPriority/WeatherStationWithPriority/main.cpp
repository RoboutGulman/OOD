#include "stdafx.h"

#include "Display.h"
#include "TemperatureStatsDisplay.h"
#include "WeatherData.h"

int main()
{
    WeatherData wd;

    Display display(std::cout);
    wd.RegisterObserver(display, 1);

    TemperatureStatsDisplay statsDisplay(std::cout);
    wd.RegisterObserver(statsDisplay, 2);

    wd.SetMeasurements(3, 0.7, 760);
    wd.SetMeasurements(4, 0.8, 761);

    wd.RemoveObserver(statsDisplay);

    wd.SetMeasurements(10, 0.8, 761);
    wd.SetMeasurements(-10, 0.8, 761);
    return 0;
}
