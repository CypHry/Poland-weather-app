#ifndef CITY_H
#define CITY_H

#include <QGraphicsTextItem>
#include <QObject>
#include <QGraphicsScene>
#include <QFileInfo>
#include <weather_data.h>
#include <weather_data_caller.h>
#include <weather_data_reader.h>
#include <vector>


/** @file city.h
 *  @brief File contains  declaration of city class.
 *
 *  The city class is used for getting and storing weather data for specific city.
 *  It also holds QGraphicsTextItems that are displayed on the main map of Poland (city_name and weather_text).
 */

/**@class city
 * @brief Class used for storing weather data and QGraphicsItems displayed on map of Poland for specific city.
 *
 * While object of city class is being created it gets weather data for specified (by CITY_ID param in constructor) city
 * from server and parse them. All the weather data for currently displayed day are contained in data member.
 * Class has also QGraphicsTextItem members that are displayed on the map of poland (scene param in constructor).
 *
 */
class city : public QObject
{
    Q_OBJECT

private:
    CITY_ID city_id; ///< City ID given as a parameter in constructor. Specifies the created city.
    weather_data* data; ///< Pointer to container for all the weather data
    QGraphicsTextItem* weather_text; ///< Pointer to text that is currently displayed on map scene under the city name
    QGraphicsTextItem* city_name; ///< Pointer to city name displayed on map scene
    weather_data_caller* data_caller; ///< Pointer to data_caller class used for getting json from weather server


public:
    /** @brief Constructor
     *
     * Gets data for specific city and sets city_name item (text and position on QGraphicsScene).
     *
     * @param city_id - specifies city to be created
     * @param scene - QGraphicsScene (map of Poland) where texts are going to be displayed
     */
    city(const CITY_ID city_id, QGraphicsScene* scene);

    QGraphicsTextItem* get_city_name_ptr() const {return city_name;}

    void update(const QDate new_date, const QTime new_time);

    /** @brief Destructor
     *
     *  Deletes all dynamically created class members (data, data_caller, weather_text, city_name).
     */
    ~city() {delete data; delete data_caller; delete weather_text; delete city_name;}

public slots:
    /** @brief Sets current weather_text (as temperature) on QGraphicsScene (map of Poland).
     *
     *  Connected to data_parsed signal from weather_data class. Changes the weather_text from "" to current temp.
     */
    void set_weather_text();

};


#endif //CITY_H
