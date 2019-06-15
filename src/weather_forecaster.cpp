#include "weather_forecaster.h"
/** @file
 *
 * @brief @link weather_forecaster @endlink class source file.
 */

weather_forecaster::weather_forecaster()
{
    data = new weather_forecast_data(this);
    caller = new weather_data_caller(data);
    saver = new weather_data_saver();
}

void weather_forecaster::save_data()
{
    QString filename;
    QString city_name;
    if(data->get_city() == "Wroclaw")
        city_name = "Wroclaw ";
    else if(data->get_city() == "Warsaw")
        city_name = "Warsaw ";
    else if(data->get_city() == "Katowice")
        city_name = "Katowice ";
    else if(data->get_city() == "Poznan")
        city_name = "Poznan ";
    else if(data->get_city() == "Gdansk")
        city_name = "Gdansk ";
    else if(data->get_city() == "Krakow")
        city_name = "Krakow ";

    for(unsigned int i = 0; i < data->get_dates().size(); i++)
    {
        filename = "weather_data/";
        filename.append(city_name);
        filename.append(*data->get_dates()[i]);
        saver->save_json_string_to_file(*data->get_json_strings()[i], filename);
    }
}

void weather_forecaster::update()
{
    caller->set_request_url(QUrl("https://api.openweathermap.org/data/2.5/forecast?q=Wroclaw&units=metric&appid=63fe817b1ae0e5f3a6986eeecad1eb2d"));
    caller->get_data();
    caller->set_request_url(QUrl("https://api.openweathermap.org/data/2.5/forecast?q=Warszawa&units=metric&appid=63fe817b1ae0e5f3a6986eeecad1eb2d"));
    caller->get_data();
    caller->set_request_url(QUrl("https://api.openweathermap.org/data/2.5/forecast?q=Katowice&units=metric&appid=63fe817b1ae0e5f3a6986eeecad1eb2d"));
    caller->get_data();
    caller->set_request_url(QUrl("https://api.openweathermap.org/data/2.5/forecast?q=Poznan&units=metric&appid=63fe817b1ae0e5f3a6986eeecad1eb2d"));
    caller->get_data();
    caller->set_request_url(QUrl("https://api.openweathermap.org/data/2.5/forecast?q=Gdansk&units=metric&appid=63fe817b1ae0e5f3a6986eeecad1eb2d"));
    caller->get_data();
    caller->set_request_url(QUrl("https://api.openweathermap.org/data/2.5/forecast?q=Krakow&units=metric&appid=63fe817b1ae0e5f3a6986eeecad1eb2d"));
    caller->get_data();
}