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

/**@file weather_animation.h
 * @brief File contains the declaration of weather_animation class.
 *
 * Weather animation class is used for displaying animation on the map of Poland.
 */


/**
 * @enum ICON_TYPES
 * @brief All types of icons that can be displayed/animated in the app.
 */
enum ICON_TYPES {CLOUDY, CLOUDY_DAY, DAY, RAINY, RAINY_DAY, THUNDER};

/**@class weather_animation
 * @brief Weather animation class is used for displaying animation of weather for the specific city on the map of Poland.
 *
 */
class weather_animation : public QObject
{
    Q_OBJECT

private:
    std::array<QPixmap, 4> icons; ///< All currently used icons.
    QGraphicsPixmapItem* current_item; ///< Currently displayed icon on the map of Poland.
    unsigned int current_icon; ///< Iterator specifying currently displayed icon on the map.

    QTimer timer; ///< Timer used for animation.

public:
    /**@brief Constructor
     *
     * Adds @link current_item @endlink to the map of Poland.
     *
     * @param scene - the map of Poland
     */
    weather_animation(QGraphicsScene* scene);

    /**@brief Current item getter
     *
     * Returns currently displayed icon.
     *
     * @return @link current_item @endlink
     */
    QGraphicsPixmapItem* get_current_item() const {return current_item;};

    /**@brief Sets position for the animated icon.
     *
     * @param X
     * @param Y
     */
    void set_position(const unsigned int X, const unsigned int Y);

    /**@brief Change currently animated icon to the new one.
     *
     * @param new_icon_type
     */
    void change_icons(const ICON_TYPES new_icon_type);

    /**@brief Starts @link timer @endlink (500 ms).
     *
     */
    void start_timer() {timer.start(500);}

    /**@brief Stops @link timer @endlink.
    *
    */
    void stop_timer() {timer.stop();}

    /**@brief Destructor
     *
     * Deletes @link current_item @endlink.
     */
    ~weather_animation(){delete current_item;}
public slots:
    /**@brief Increases @link current_icon @endlink and sets new item that is displayed on the map of Poland.
     *
     */
    void update();

};

#endif //POGODA_WEATHER_ANIMATION_H
