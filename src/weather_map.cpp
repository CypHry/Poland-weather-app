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

    currently_used_date = QDate::currentDate();
    currently_used_time = QTime::currentTime();

    QObject::connect(scene, SIGNAL(selectionChanged()), this, SLOT(check_selected()));
}


void weather_map::update_date(QDate new_date)
{
    currently_used_date = new_date;
    for(unsigned int i = 0; i < cities.size(); i++)
    {
        cities[i]->update(currently_used_date, currently_used_time);
    }
}

void weather_map::update_time(QTime new_time)
{
    currently_used_time = new_time;
    for(unsigned int i = 0; i < cities.size(); i++)
    {
        cities[i]->update(currently_used_date, currently_used_time);
    }
}

void weather_map::check_selected()
{
    for(unsigned int i = 0; i < cities.size(); i++)
    {
        if(cities[i]->get_city_name_ptr()->isSelected())
        {
            emit city_selected(cities[i]);
            return;
        }
    }
}
