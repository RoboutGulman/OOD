// TemplateTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../WeatherStationDuo/stdafx.h"

#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"
#include "../WeatherStationDuo/Display.h"
#include "../WeatherStationDuo/StatsDisplay.h"
#include "../WeatherStationDuo/WeatherData.h"

SCENARIO("observer priority")
{
    std::ostringstream strmOut;
    WeatherData wdInside, wdOutside;

    Display display(strmOut, &wdInside, &wdOutside);

    WHEN("only one subject changes")
    {
        wdInside.SetMeasurements(3, 0.7, 760);
        THEN("observer updates one time and outputs the initiator of the update")
        {

            CHECK(strmOut.str() ==
                  "weather inside:\nCurrent Temp 3\nCurrent Hum 0.7\nCurrent Pressure 760\n----------------\n");
        }
    }
    WHEN("two subjects change")
    {
        wdInside.SetMeasurements(3, 0.7, 760);
        wdOutside.SetMeasurements(4, 0.8, 761);
        THEN("the observer can determine from whom the subject received the information")
        {
            CHECK(strmOut.str() ==
                  "weather inside:\nCurrent Temp 3\nCurrent Hum 0.7\nCurrent Pressure 760\n----------------\n"
                  "weather outside:\nCurrent Temp 4\nCurrent Hum 0.8\nCurrent Pressure 761\n----------------\n");
        }
    }
    WHEN("observer subscribe on the new subject")
    {
        WeatherData weatherInTown;
        weatherInTown.RegisterObserver(display);
        weatherInTown.SetMeasurements(10, 0.8, 761);
        THEN("observer receives the data from new subject")
        {
            CHECK(strmOut.str() ==
                  "unknown source:\nCurrent Temp 10\nCurrent Hum 0.8\nCurrent Pressure 761\n----------------\n");
        }
    }
    WHEN("observer unsubscribe from one the subject")
    {
        wdInside.RemoveObserver(display);
        wdInside.SetMeasurements(10, 0.8, 761);
        THEN("observer does not receive the data from subject")
        {
            CHECK(strmOut.str() == "");
        }
    }
}
