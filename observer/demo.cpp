#include "weather-data.hpp"
#include "weather-display.hpp"

int main() {

    WeatherData *weatherData = new WeatherData();

    CurrentConditionsDisplay *currentDisplay = new CurrentConditionsDisplay(weatherData);
    StatisticsDisplay *statisticsDisplay = new StatisticsDisplay(weatherData);
    ForecastDisplay *forecastDisplay = new ForecastDisplay(weatherData);

    weatherData->setMeasurements(80, 65, 30.4f);
    weatherData->setMeasurements(82, 70, 29.2f);
    weatherData->setMeasurements(78, 90, 29.2f);

    weatherData->removeObserver(forecastDisplay);
    weatherData->setMeasurements(84, 86, 28.2f);

    delete currentDisplay;
    delete statisticsDisplay;
    delete forecastDisplay;

    delete weatherData;

    return 0;
}
