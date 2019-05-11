#ifndef WEATHER_MAP_H
#define WEATHER_MAP_H

#include <vector>
#include <memory>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QWidget>
#include <city.h>

/**@file weather_map.h
 * @brief File provides a class used for creating map's graphics scene.\
 *
 * Class weather_map contains scene of all objects displayed on the map and pointer to the background image.
 * There is also a std::vector of all the cities used in the app.
 */

/**@class weather_map
 * @brief Class represents map of poland.
 *
 * Class contains scene of all objects displayed on the map and pointer to the background image.
 * There is also a std::vector of all the cities used in the app.
 */
class weather_map : public QObject
{
    Q_OBJECT

private:
    QGraphicsScene* scene; ///< Scene of all graphics items displayed on the map of poland and the map itself.
    QGraphicsPixmapItem* map_img; ///< Pointer to the map of poland background image.
    std::vector<std::shared_ptr<city>> cities; ///< Vector of all the cities used in the app.
    QDate currently_used_date;
    QTime currently_used_time;

public:
    /** @brief weather_map constructor
     *
     *  Sets map img and creates cities.
     *  Cities and map are added to the main graphics scene.
     */
    weather_map();

    /** @brief scene pointer getter
     *
     * Returns pointer to the main graphics scene.
     * @return scene
     */
    QGraphicsScene* get_scene_ptr() {return scene;}

    /**@brief Destructor
     *
     * Deletes the main graphics scene.
     */
    ~weather_map(){scene->clearSelection(); cities.clear(); delete scene;}

public slots:
    void update_date(QDate new_date);
    void update_time(QTime new_time);
    void check_selected();

signals:
    void change_scene(std::shared_ptr<city> selected_city);

};

#endif // WEATHER_MAP_H
