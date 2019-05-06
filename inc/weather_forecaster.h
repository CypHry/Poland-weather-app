#ifndef WEATHER_FORECASTER_H
#define WEATHER_FORECASTER_H

#include "weather_data_saver.h"
#include "weather_data_caller.h"

class weather_forecaster : public QObject
{
    Q_OBJECT

private:
    weather_data_saver* saver;
    weather_data_caller* caller;
    weather_data* data; // change to weather forecast data!
public:
    weather_forecaster();
    void update();

public slots:
    void save_data();
};




#endif //WEATHER_FORECASTER_H
