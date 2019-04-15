#include <city.h>

city::city(const CITY city_id, QGraphicsScene* scene)
{
    this->city_id = city_id;
    data = new weather_data();
    data_caller = new weather_data_caller(data);

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

}

