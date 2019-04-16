#ifndef POGODA_CITY_H
#define POGODA_CITY_H

#include <QGraphicsTextItem>
#include <QObject>
#include <QGraphicsScene>
#include <weather_data.h>
#include <weather_data_caller.h>
#include <weather_data_reader.h>
#include <vector>


/** @file weather_data.h
 *  @brief File contains  declaration of city class.
 */

/**@class Class used for storing weather data and QGraphicsItems for specific city.
 *
 */
class city : public QObject
{
    Q_OBJECT

private:
    CITY_ID city_id;
    weather_data* data;
    QGraphicsTextItem* weather_text;
    QGraphicsTextItem* city_name;
    weather_data_caller* data_caller;


public:
    /** @brief Constructor
     *
     * Gets data for specific city and sets city_name item (text and position on QGraphicsScene).
     *
     * @param city_id - specifies used city
     * @param scene
     */
    city(const CITY_ID city_id, QGraphicsScene* scene);

public slots:
    /** @brief Sets current weather_text on main map QGraphicsScene
     *
     *  Connected to data_parsed signal from weather_data class.
     */
    void set_weather_text();

};


#endif //POGODA_CITY_H
