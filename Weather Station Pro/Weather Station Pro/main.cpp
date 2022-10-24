#include "stdafx.h"

#include "Display.h"
#include "StatsDisplay.h"
#include "WeatherData.h"

int main()
{
	WeatherData wd;

	Display display;
	// wd.RegisterObserver(display);

	StatsDisplay statsDisplay;
	wd.RegisterObserver(statsDisplay);

	wd.SetMeasurements(3, 0.7, 760, { 8, 90 });
	wd.SetMeasurements(3, 0.7, 760, { 8, 270 });
	wd.SetMeasurements(4, 0.8, 761, { 6, 120 });

	// wd.RemoveObserver(statsDisplay);

	wd.SetMeasurements(10, 0.8, 761, { 3, 270 });
	wd.SetMeasurements(-10, 0.8, 761, { 2, 0 });
	return 0;
}
