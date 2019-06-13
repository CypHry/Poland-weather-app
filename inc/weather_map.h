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
#include <weather_animation.h>

/**@file weather_map.h
 * @brief File provides the class used for creating map's graphics scene.
 *
 * Class weather_map contains the scene of all objects displayed on the map and the background image.
 */

/**@class weather_map
 * @brief Class represents map of poland.
 *
 * Class contains scene of all objects displayed on the map and pointer to the background image.
 */
class weather_map : public QObject
{
    Q_OBJECT

private:
    QGraphicsScene* scene; ///< Scene of all graphics items displayed on the map of poland and the map itself.
    QGraphicsPixmapItem* map_img; ///< Pointer to the map of Poland background image.
    std::vector<std::shared_ptr<city>> cities; ///< Vector of all the cities used in the app.
    QDate currently_used_date; ///< Currently used date in the app.
    QTime currently_used_time; ///< Currently used time in the app.


    weather_animation* animation;
public:
    /** @brief Constructor
     *
     *  Sets map's background image. All the cities are added to the map of Poland.
     */
    weather_map();

    /** @brief Scene pointer getter
     *
     * Returns pointer to the map's graphics scene.
     * @return @link weather_map::scene @endlink
     */
    QGraphicsScene* get_scene_ptr() {return scene;}

    /**@brief Destructor
     *
     * Deletes the map of Poland.
     */
    ~weather_map(){scene->clearSelection(); cities.clear(); delete scene;}

public slots:
    /**@brief Updates weather data for all cities after changing date.
     *
     * @param new_data
     */
    void update_date(QDate new_date);

    /**@brief Updates weather data for all cities after changing the time.
     *
     * @param new_time
     */
    void update_time(QTime new_time);

    /**@brief Checks if a city was selected and if it was emits change_scene signal with the selected city as a param.
     *
     */
    void check_selected();

signals:
    /**@brief Signal emitted after selecting a city on the map.
     *
     * @param selected city
     */
    void city_selected(std::shared_ptr<city> selected_city);

};

#endif // WEATHER_MAP_H
