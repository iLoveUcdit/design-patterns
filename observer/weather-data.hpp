#include "subject.hpp"

#ifndef _WEATHER_DATA_HPP_
#define _WEATHER_DATA_HPP_

class WeatherData : public Subject {
public:
    WeatherData() {
        m_temperature = 0;
        m_humidity = 0;
        m_pressure = 0;
    }
    virtual ~WeatherData() {}
    void measurementsChanged() {
        Subject::notifyObservers();
    }
    void setMeasurements(float temperature, float humidity, float pressure) {
        m_temperature = temperature;
        m_humidity = humidity;
        m_pressure = pressure;
        measurementsChanged();
    }
    float getTemperature() {
        return m_temperature;
    }
    float getHumidity() {
        return m_humidity;
    }
    float getPressure() {
        return m_pressure;
    }

private:
    float m_temperature;
    float m_humidity;
    float m_pressure;
};

#endif // _WEATHER_DATA_HPP_
