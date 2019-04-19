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
 * @brief File provides a class used for creating map's graphics scene.
 */

/**@class weather_map
 * @brief Class represents QGraphicsScene for map of poland
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
    /** @brief weather_map constructor
     *
     *  Sets map img and creates cities.
     */
    weather_map();

    /** @brief scene pointer getter
     *
     * @return scene
     */
    QGraphicsScene* get_scene_ptr() {return scene;}

    /**@brief Destructor
     *
     */
    ~weather_map(){cities.clear(); delete scene;}
};

#endif // WEATHER_MAP_H
