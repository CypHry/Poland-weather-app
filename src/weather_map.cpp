#include "weather_map.h"

weather_map::weather_map()
{
    scene = new QGraphicsScene(this);
    QPixmap pix();
    pix.fill(Qt::red);
    map_img = scene->addPixmap(pix);
}
