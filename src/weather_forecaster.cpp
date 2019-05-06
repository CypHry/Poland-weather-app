#include "weather_forecaster.h"


weather_forecaster::weather_forecaster()
{
    data = new weather_data(this);
    caller = new weather_data_caller(data);
    saver = new weather_data_saver();
}

void weather_forecaster::save_data()
{
    if(saver->save_json_string_to_file(data->get_json_string(), QString("weather_data/test.txt")))
        qDebug() << QString("something went wrong with saving data (forecaster)");
}

void weather_forecaster::update()
{
    return;
}