#pragma once
#include "Observer.h"

struct WeatherInfo {
    double temperature = 0;
    double humidity = 0;
    double pressure = 0;
};

class WeatherData : public Observable<WeatherInfo> {
public:
    WeatherData();

    double GetTemperature() const;
    double GetHumidity() const;
    double GetPressure() const;

    void MeasurementsChanged();

    void SetMeasurements(double temp, double humidity, double pressure);

protected:
    WeatherInfo GetChangedData() const override;

private:
    double m_temperature;
    double m_humidity;
    double m_pressure;
};
