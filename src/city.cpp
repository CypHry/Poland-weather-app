#include <city.h>

city::city(const CITY_ID city_id, QGraphicsScene* scene)
{
    this->city_id = city_id;
    data = new weather_data(this);
    data_caller = new weather_data_caller(city_id, data);

    switch(city_id) {
        case POZNAN:
            city_name = scene->addText("Poznan");
            city_name->setPos(180,265);
            break;
        case WARSZAWA:
            city_name = scene->addText("Warszawa");
            city_name->setPos(465,270);
            break;
        case KATOWICE:
            city_name = scene->addText("Katowice");
            city_name->setPos(330,500);
            break;
        case KRAKOW:
            city_name = scene->addText("Krakow");
            city_name->setPos(380,500);
            break;
        case WROCLAW:
            city_name = scene->addText("Wroclaw");
            city_name->setPos(200,380);
            break;
        case GDANSK:
            city_name = scene->addText("Gdansk");
            city_name->setPos(270,40);
            break;
    }
    data_caller->get_data();
    weather_text = scene->addText("");
}


void city::set_weather_text()
{
    weather_text->setPlainText(QString::number(data->get_temp()));
    switch(city_id) {
        case POZNAN:
            weather_text->setPos(180+10,265+10);
            break;
        case WARSZAWA:
            weather_text->setPos(465+10,270+10);
            break;
        case KATOWICE:
            weather_text->setPos(330+10,500+10);
            break;
        case KRAKOW:
            weather_text->setPos(380+10,500+10);
            break;
        case WROCLAW:
            weather_text->setPos(200+10,380+10);
            break;
        case GDANSK:
            weather_text->setPos(270+10,40+10);
            break;
    }
}
