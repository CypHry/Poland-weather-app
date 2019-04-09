#include "weather_map.h"

weather_map::weather_map()
{
    scene = new QGraphicsScene(this);
    QPixmap pix("img/map_of_poland.png");
    map_img = scene->addPixmap(pix);
    poznan = scene->addText("Poznan");
    poznan->setPos(150,150);
    warszawa = scene->addText("Warszawa");
    warszawa->setPos(150,250);
    gdansk = scene->addText("Gdansk");
    gdansk->setPos(50,150);
    wroclaw = scene->addText("Wroclaw");
    wroclaw->setPos(350,150);
    krakow = scene->addText("Krakow");
    krakow->setPos(350,350);
    katowice = scene->addText("Katowice");
    katowice->setPos(450,250);

}
