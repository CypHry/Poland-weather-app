#include "city_info.h"


city_info::city_info()
{
    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(Qt::white);
    QFont temp_font("Akaash", -1, 50, false);
    QGraphicsTextItem* temp = scene->addText("city name:");
    temp->setPos(50, 30);
    temp->setFont(temp_font);
    temp = scene->addText("description:");
    temp->setPos(50, 50);
    temp->setFont(temp_font);
    temp = scene->addText("pressure[hPa]:");
    temp->setPos(50, 70);
    temp->setFont(temp_font);
    temp = scene->addText("temperature[Celsius]:");
    temp->setPos(50, 90);
    temp->setFont(temp_font);
    temp = scene->addText("humidity[%]:");
    temp->setPos(50, 110);
    temp->setFont(temp_font);
    temp = scene->addText("wind degrees:");
    temp->setPos(50, 130);
    temp->setFont(temp_font);
    temp = scene->addText("wind speed[m/s]:");
    temp->setPos(50, 150);
    temp->setFont(temp_font);
    temp = scene->addText("clouds[%]:");
    temp->setPos(50, 170);
    temp->setFont(temp_font);

    city_name = scene->addText("temp city name");
    city_name->setPos(200, 30);
    city_name->setFont(temp_font);
    weather_texts.push_back(scene->addText("temp description"));
    weather_texts[0]->setPos(200, 50);
    weather_texts[0]->setFont(temp_font);
    weather_texts.push_back(scene->addText("temp pressure"));
    weather_texts[1]->setPos(200, 70);
    weather_texts[1]->setFont(temp_font);
    weather_texts.push_back(scene->addText("temp temperature"));
    weather_texts[2]->setPos(200, 90);
    weather_texts[2]->setFont(temp_font);
    weather_texts.push_back(scene->addText("temp humidity"));
    weather_texts[3]->setPos(200, 110);
    weather_texts[3]->setFont(temp_font);
    weather_texts.push_back(scene->addText("temp wind deg"));
    weather_texts[4]->setPos(200, 130);
    weather_texts[4]->setFont(temp_font);
    weather_texts.push_back(scene->addText("temp wind speed"));
    weather_texts[5]->setPos(200, 150);
    weather_texts[5]->setFont(temp_font);
    weather_texts.push_back(scene->addText("temp clouds"));
    weather_texts[6]->setPos(200, 170);
    weather_texts[6]->setFont(temp_font);
}


void city_info::set_city_name(QGraphicsTextItem* new_city_name)
{
    city_name->setPlainText(new_city_name->toPlainText());
}

void city_info::update_weather_texts()
{
    weather_texts[0]->setPlainText(data->get_description());
    weather_texts[1]->setPlainText(QString::number(data->get_pressure()));
    weather_texts[2]->setPlainText(QString::number(data->get_temp()));
    weather_texts[3]->setPlainText(QString::number(data->get_humidity()));
    weather_texts[4]->setPlainText(QString::number(data->get_wind_deg()));
    weather_texts[5]->setPlainText(QString::number(data->get_wind_speed()));
    weather_texts[6]->setPlainText(QString::number(data->get_clouds()));
}

void city_info::update_parsed_data()
{
    update_weather_texts();
}