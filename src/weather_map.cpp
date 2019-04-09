#include "weather_map.h"

weather_map::weather_map()
{
    scene = new QGraphicsScene(this);
    QPixmap pix("img/map_of_poland.png");
    map_img = scene->addPixmap(pix);
    temp = scene->addText("test");
    temp->setPos(150,150);
}
