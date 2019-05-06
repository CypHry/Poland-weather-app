#include "weather_forecaster.h"


weather_forecaster::weather_forecaster()
{
    data = new weather_forecast_data(this);
    caller = new weather_data_caller(data);
    saver = new weather_data_saver();
}

void weather_forecaster::save_data()
{
    saver->save_json_string_to_file(data->test_string, QString("weather_data/test.txt"));
}

void weather_forecaster::update()
{
    caller->set_request_url(QUrl("https://api.openweathermap.org/data/2.5/forecast?q=Wroclaw&units=metric&appid=63fe817b1ae0e5f3a6986eeecad1eb2d"));
    caller->get_data();
}