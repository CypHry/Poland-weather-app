#ifndef WEATHER_FORECASTER_H
#define WEATHER_FORECASTER_H

#include "weather_data_saver.h"
#include "weather_data_caller.h"

class weather_forecaster
{
    weather_data_saver* saver;
    weather_data_caller* caller;
    weather_data* data;
public:
    weather_forecaster();
    void forecast_update();
};




#endif //WEATHER_FORECASTER_H
