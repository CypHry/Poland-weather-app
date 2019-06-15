#ifndef POGODA_CITY_INFO_H
#define POGODA_CITY_INFO_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <city.h>
#include <memory>

/**@file city_info.h
 *
 * @brief The file contains the declaration of city_info class.
 * city_info contains specific information for a currently displayed city.
 * The information are displayed on its scene and updated after changing data/timeedits.
 */


/**@class city_info
 * @brief city_info contains specific information for a currently displayed city
 *
 * The information are displayed by a QGraphicsView (created in QtDesigner) connected to the
 * QGraphicsScene from the class. The information are updated after changing the data/timeedit.
 *
 */
class city_info : public QObject
{
    Q_OBJECT

private:
    QGraphicsScene* scene; ///< Scene connected to the main QGraphicsView (created in QtDesigner) that displays all the information,
    std::vector<QGraphicsTextItem*> weather_texts; ///< Pointers to items displayed on the scene that represents the weather information.
    QGraphicsTextItem* city_name; ///< Text item that contains currently displayed name of the city.
    weather_data* data; ///< Pointer to the currently displayed weather data.

public:
    /**@brief Constructor
     *
     * Adds weather information to the scene and sets their positions.
     */
    city_info();

    /**@brief scene getter
     *
     * @return @link city_info::scene @endlink
     */
    QGraphicsScene* get_scene_ptr() const {return scene;}

    /**@brief Sets new weather data.
     *
     * @param new_data
     */
    void set_data(weather_data* new_data){data = new_data; data->notify_after_data_parsed(this);}

    /**@brief Sets new city name.
     *
     * @param new_city_name
     */
    void set_city_name(QGraphicsTextItem* new_city_name);

    /**@brief Updates weather text items.
     *
     * Updates text items displayed on the scene after updating weather data.
     */
    void update_weather_texts();


public slots:

    /**@brief Updates weather texts after parsing the data.
     *
     */
    void update_parsed_data();

};



#endif //POGODA_CITY_INFO_H
