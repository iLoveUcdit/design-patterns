#include "observer.hpp"
#include "weather-data.hpp"

#include <iostream>
#include <algorithm>
#include <limits>

#ifndef _WEATHER_DISPLAY_HPP_
#define _WEATHER_DISPLAY_HPP_

class StatisticsDisplay : public Observer {
public:
    StatisticsDisplay(WeatherData *weatherData) {
        m_maxTemp = std::numeric_limits<float>::min();
        m_minTemp = std::numeric_limits<float>::max();
        m_tempSum = 0;
        m_numReadings = 0;
        m_weatherData = weatherData;
        weatherData->registerObserver(this);
    }
    virtual ~StatisticsDisplay() {}
    void update() {
        float temp = m_weatherData->getTemperature();
        m_maxTemp = std::max(m_maxTemp, temp);
        m_minTemp = std::min(m_minTemp, temp);
        m_tempSum += temp;
        ++m_numReadings;
        display();
    }
    void display() {
        std::cout << "Avg/Max/Min temperature = " << (m_tempSum / m_numReadings)
                  << "/" << m_maxTemp << "/" << m_minTemp << "." << std::endl;
    }

private:
    float m_maxTemp;
    float m_minTemp;
    float m_tempSum;
    int m_numReadings;
    WeatherData *m_weatherData;
};

class CurrentConditionsDisplay : public Observer {
public:
    CurrentConditionsDisplay(WeatherData *weatherData) {
        m_temp = 0;
        m_humidity = 0;
        m_weatherData = weatherData;
        weatherData->registerObserver(this);
    }
    virtual ~CurrentConditionsDisplay() {}
    void update() {
        m_temp = m_weatherData->getTemperature();
        m_humidity = m_weatherData->getHumidity();
        display();
    }
    void display() {
        std::cout << "Current conditions: " << m_temp << "F degrees and "
                  << m_humidity << "% humidity." << std::endl;
    }

private:
    float m_temp;
    float m_humidity;
    WeatherData *m_weatherData;
};

class ForecastDisplay : public Observer {
public:
    ForecastDisplay(WeatherData *weatherData) {
        m_currentPressure = 0;
        m_lastPressure = 0;
        m_weatherData = weatherData;
        weatherData->registerObserver(this);
    }
    virtual ~ForecastDisplay() {}
    void update() {
        m_lastPressure = m_currentPressure;
        m_currentPressure = m_weatherData->getPressure();
        display();
    }
    void display() {
        std::cout << "Forecast: ";
        if (m_currentPressure > m_lastPressure) {
            std::cout << "Improving weather on the way!" << std::endl;
        } else if (m_currentPressure == m_lastPressure) {
            std::cout << "More of the same." << std::endl;
        } else {
            std::cout << "Watch out for cooler, rainy weather." << std::endl;
        }
    }

private:
    float m_currentPressure;
    float m_lastPressure;
    WeatherData* m_weatherData;
};

#endif // _WEATHER_DISPLAY_HPP_
