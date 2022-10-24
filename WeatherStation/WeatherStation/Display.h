#pragma once
#include "WeatherData.h"

class Display : public IObserver<WeatherInfo> {
    void Update(const WeatherInfo& data) override;
};
