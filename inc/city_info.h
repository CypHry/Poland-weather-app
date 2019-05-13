#ifndef POGODA_CITY_INFO_H
#define POGODA_CITY_INFO_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <city.h>
#include <memory>




class city_info : public QObject
{
    Q_OBJECT

private:
    QGraphicsScene* scene;
    std::vector<QGraphicsTextItem*> weather_texts;
    QGraphicsTextItem* back_text;
    QGraphicsTextItem* city_name;
    weather_data* data;

public:
    city_info();
    QGraphicsScene* get_scene_ptr() const {return scene;}
    void set_data(weather_data* new_data){data = new_data; data->notify_after_data_parsed(this);}
    void set_city_name(QGraphicsTextItem* new_city_name);
    void update_weather_texts();

signals:
    void change_scene();

public slots:
    void back_selected();
    void data_parsed();

};



#endif //POGODA_CITY_INFO_H
