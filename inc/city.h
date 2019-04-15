#ifndef POGODA_CITY_H
#define POGODA_CITY_H

#include <QGraphicsTextItem>
#include <QObject>
#include <QGraphicsScene>
#include <weather_data.h>
#include <weather_data_caller.h>
#include <weather_data_reader.h>

class city : public QObject
{
    Q_OBJECT

private:
    CITY city_id;
    weather_data* data;
    // chart data
    QGraphicsTextItem* city_name;
    weather_data_caller* data_caller;


public:
    city(const CITY city_id, QGraphicsScene* scene);

    const QGraphicsTextItem* get_city_name() const {return city_name;}
    CITY get_city_id() const {return city_id;}
};


#endif //POGODA_CITY_H
