#include "weather_data.h"

void weather_data::parse_from_string(QString answer)
{
    json_string = answer;

    QJsonDocument json = QJsonDocument::fromJson(answer.toUtf8());
    QJsonObject obj = json.object();
    QJsonArray weather_array = obj.value("weather").toArray();
    QJsonObject weather_obj = weather_array.last().toObject();
    QJsonObject main_obj = obj.value("main").toObject();
    QJsonObject wind_obj = obj.value("wind").toObject();
    QJsonObject cloud_obj = obj.value("clouds").toObject();

    city_name = obj.value("name").toString();
    description = weather_obj.value("description").toString();
    pressure = main_obj.value("pressure").toInt();
    temp = main_obj.value("temp").toDouble();
    humidity = main_obj.value("humidity").toInt();
    wind_deg = wind_obj.value("deg").toInt();
    wind_speed = wind_obj.value("speed").toDouble();
    clouds = cloud_obj.value("all").toInt();
    rain = obj.value("rain").toInt();
    snow = obj.value("snow").toInt();

    emit data_parsed();
}

weather_data::weather_data(QObject* parent)
{
    QObject::connect(this, SIGNAL(data_parsed()), parent, SLOT(set_weather_text()));
}
