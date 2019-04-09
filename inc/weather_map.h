#ifndef WEATHER_MAP_H
#define WEATHER_MAP_H

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QObject>

/**@file weather_map.h
 *
 * file provides a class used for creating map's graphics scene
 */

class weather_map : public QObject
{
    Q_OBJECT

private:
    QGraphicsScene* scene;
    QGraphicsPixmapItem* map_img;
    QGraphicsTextItem* temp;

public:
    weather_map();
    QGraphicsScene* get_scene_ptr() {return scene;}
};

#endif // WEATHER_MAP_H
