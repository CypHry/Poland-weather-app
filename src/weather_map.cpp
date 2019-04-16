#include "weather_map.h"

weather_map::weather_map()
{
    scene = new QGraphicsScene(this);
    QPixmap pix("img/map_of_poland.png");
    map_img = scene->addPixmap(pix);

    for(int i = 0; i < NUMBER_OF_CITIES; i++)
    {
        std::shared_ptr <city> temp = std::make_shared<city>(static_cast<CITY_ID>(i), scene);
        cities.push_back(temp);
    }

}
