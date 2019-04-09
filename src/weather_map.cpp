#include "weather_map.h"

weather_map::weather_map()
{
    scene = new QGraphicsScene(this);
    QPixmap pix("img/map_of_poland.png");
    map_img = scene->addPixmap(pix);
    poznan = scene->addText("Poznan");
    poznan->setPos(180,265);
    warszawa = scene->addText("Warszawa");
    warszawa->setPos(465,270);
    gdansk = scene->addText("Gdansk");
    gdansk->setPos(270,40);
    wroclaw = scene->addText("Wroclaw");
    wroclaw->setPos(200,380);
    krakow = scene->addText("Krakow");
    krakow->setPos(380,500);
    katowice = scene->addText("Katowice");
    katowice->setPos(330,500);

}
