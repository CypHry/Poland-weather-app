#ifndef POGODA_CITY_INFO_H
#define POGODA_CITY_INFO_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

class city_info : public QObject
{
    Q_OBJECT

private:
    QGraphicsScene* scene;
    std::vector<QGraphicsTextItem*> weather_texts;
    QGraphicsTextItem* back_text;

public:
    city_info();
    QGraphicsScene* get_scene_ptr() const {return scene;}

signals:
    void change_scene();

public slots:
    void back_selected();

};



#endif //POGODA_CITY_INFO_H
