#include "stdafx.h"

#include "Display.h"
#include "StatsDisplay.h"
#include "WeatherData.h"

int main()
{
    WeatherData wdInside, wdOutside;

    Display display(std::cout, &wdInside, &wdOutside);
    wdInside.RegisterObserver(display);

    StatsDisplay statsDisplay(&wdInside, &wdOutside);
    wdInside.RegisterObserver(statsDisplay);

    wdInside.SetMeasurements(3, 0.7, 760);
    wdInside.SetMeasurements(4, 0.8, 761);

    wdInside.RemoveObserver(statsDisplay);

    wdInside.SetMeasurements(10, 0.8, 761);
    wdInside.SetMeasurements(-10, 0.8, 761);
    return 0;
}
