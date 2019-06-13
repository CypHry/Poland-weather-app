//
// Created by cyprian on 12/06/19.
//

#ifndef POGODA_WEATHER_ANIMATION_H
#define POGODA_WEATHER_ANIMATION_H

#include <QObject>
#include <QTimer>
#include <QPixmap>
#include <array>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QDebug>


enum ICON_TYPES {CLOUDY, CLOUDY_DAY, DAY, RAINY, RAINY_DAY, THUNDER};

class weather_animation : public QObject
{
    Q_OBJECT

private:
    std::array<QPixmap, 4> icons;
    QGraphicsPixmapItem* current_item;
    unsigned int current_icon;

    QTimer timer;

public:
    weather_animation(QGraphicsScene* scene);

    QGraphicsPixmapItem* get_current_item() const {return current_item;}
    void set_position(const unsigned int X, const unsigned int Y);
    void change_icons(const ICON_TYPES new_icon_type);

    void start_timer() {timer.start(500);}
    void stop_timer() {timer.stop();}

    ~weather_animation(){delete current_item;}
public slots:
    void update();

};

#endif //POGODA_WEATHER_ANIMATION_H
