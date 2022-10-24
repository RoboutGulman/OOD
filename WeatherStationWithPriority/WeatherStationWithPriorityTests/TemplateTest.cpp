// TemplateTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../WeatherStationWithPriority/stdafx.h"

#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"
#include "../WeatherStationWithPriority/Display.h"
#include "../WeatherStationWithPriority/HumidityStatsDisplay.h"
#include "../WeatherStationWithPriority/PressureStatsDisplay.h"
#include "../WeatherStationWithPriority/TemperatureStatsDisplay.h"
#include "../WeatherStationWithPriority/WeatherData.h"

SCENARIO("observer priority")
{
    WeatherData wd;

    std::ostringstream strmOut;
    Display display(strmOut);
    TemperatureStatsDisplay temperatureStatsDisplay(strmOut);
    HumidityStatsDisplay himidityStatsDisplay(strmOut);
    PressureStatsDisplay pressureStatsDisplay(strmOut);

    WHEN("we register 2 observers with the different priority")
    {
        wd.RegisterObserver(display, 2);
        wd.RegisterObserver(temperatureStatsDisplay, 1);
        wd.SetMeasurements(3, 0.7, 760);

        THEN("the observer with the highest priority will get the changes first")
        {
            CHECK(
                strmOut.str() ==
                "Current Temp 3\nCurrent Hum 0.7\nCurrent Pressure 760\n----------------\n"
                "Max temperature 3.000000\nMin temperature 3.000000\nAverage temperature 3.000000\n----------------\n");
        }
    }
    WHEN("we register 2 observers with the same priority and 2 with different priority")
    {
        wd.RegisterObserver(himidityStatsDisplay, 2);
        wd.RegisterObserver(pressureStatsDisplay, 3);
        wd.RegisterObserver(display, 1);
        wd.RegisterObserver(temperatureStatsDisplay, 2);
        wd.SetMeasurements(3, 0.7, 760);
        THEN("observers with the same priority are updated in the order of subscription to the subject")
        {
            CHECK(strmOut.str() ==
                  "Max pressure 760.000000\nMin pressure 760.000000\nAverage pressure 760.000000\n----------------\n"
                  "Max humidity 0.700000\nMin humidity 0.700000\nAverage humidity 0.700000\n----------------\n"
                  "Max temperature 3.000000\nMin temperature 3.000000\nAverage temperature 3.000000\n----------------\n"
                  "Current Temp 3\nCurrent Hum 0.7\nCurrent Pressure 760\n----------------\n");
        }
    }
    // добавить тест: при добавлении уже имеющегося подписчика кол-во подписчиков не изменяется
    WHEN("we register same observer 2 times with yhe different priority")
    {
        wd.RegisterObserver(himidityStatsDisplay, 2);
        wd.RegisterObserver(display, 1);
        wd.SetMeasurements(3, 0.7, 760);
        strmOut << "register same observer second time\n";
        wd.RegisterObserver(display, 3);
        wd.SetMeasurements(10, 0.8, 761);
        THEN("observer change his priority updated only 1 time")
        {
            CHECK(strmOut.str() ==
                  "Max humidity 0.700000\nMin humidity 0.700000\nAverage humidity 0.700000\n----------------\n"
                  "Current Temp 3\nCurrent Hum 0.7\nCurrent Pressure 760\n----------------\n"
                  "register same observer second time\n"
                  "Current Temp 10\nCurrent Hum 0.8\nCurrent Pressure 761\n----------------\n"
                  "Max humidity 0.800000\nMin humidity 0.700000\nAverage humidity 0.750000\n----------------\n");
        }
    }
    
}
