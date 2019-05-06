#include "weather_forecaster.h"


weather_forecaster::weather_forecaster()
{
    data = new weather_forecast_data(this);
    caller = new weather_data_caller(data);
    saver = new weather_data_saver();
}

void weather_forecaster::save_data()
{
    return;
}

void weather_forecaster::update()
{
    return;
}