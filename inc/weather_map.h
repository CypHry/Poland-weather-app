#ifndef WEATHER_MAP_H
#define WEATHER_MAP_H

#include <vector>
#include <memory>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <city.h>

/**@file weather_map.h
 *
 * file provides a class used for creating map's graphics scene
 */

/** @brief class represents QGraphicsScene for map of poland
 *
 */
class weather_map : public QObject
{
    Q_OBJECT

private:
    QGraphicsScene* scene;
    QGraphicsPixmapItem* map_img;
    std::vector<std::shared_ptr<city>> cities;


public:
    weather_map();
    QGraphicsScene* get_scene_ptr() {return scene;}
};

#endif // WEATHER_MAP_H
