#include "weather_animation.h"

weather_animation::weather_animation(QGraphicsScene* scene) : current_icon(0)
{
    current_item = scene->addPixmap(icons[0]);
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
}

void weather_animation::update()
{
    if(current_icon == 3)
        current_icon = 0;
    else
        current_icon ++;
    start_timer();
    current_item->setPixmap(icons[current_icon]);
}

void weather_animation::set_position(const unsigned int X, const unsigned int Y)
{
    current_item->setPos(X, Y+20);
}

void weather_animation::change_icons(const ICON_TYPES new_icon_type)
{
    switch(new_icon_type)
    {
        case CLOUDY:
            icons[0].load("img/cloudy1.png");
            icons[1].load("img/cloudy2.png");
            icons[2].load("img/cloudy3.png");
            icons[3].load("img/cloudy2.png");
            break;
        case CLOUDY_DAY:
            icons[0].load("img/cloudy-day-1.png");
            icons[1].load("img/cloudy-day-2.png");
            icons[2].load("img/cloudy-day-3.png");
            icons[3].load("img/cloudy-day-2.png");
            break;
        case DAY:
            icons[0].load("img/day1.png");
            icons[1].load("img/day2.png");
            icons[2].load("img/day3.png");
            icons[3].load("img/day2.png");
            break;
        case RAINY:
            icons[0].load("img/rainy1.png");
            icons[1].load("img/rainy2.png");
            icons[2].load("img/rainy3.png");
            icons[3].load("img/rainy2.png");
            break;
        case RAINY_DAY:
            icons[0].load("img/rainy-day1.png");
            icons[1].load("img/rainy-day2.png");
            icons[2].load("img/rainy-day3.png");
            icons[3].load("img/rainy-day4.png");
            break;
        case THUNDER:
            icons[0].load("img/thunder1.png");
            icons[1].load("img/thunder2.png");
            icons[2].load("img/thunder3.png");
            icons[3].load("img/thunder2.png");
            break;
    }
}
