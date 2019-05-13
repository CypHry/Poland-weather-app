#ifndef WEATHER_FORECASTER_H
#define WEATHER_FORECASTER_H

#include "weather_data_saver.h"
#include "weather_data_caller.h"
#include "weather_forecast_data.h"

/**@file weather_forecaster.h
 * @brief File contains weather_forecaster class used for getting and saving forecast data in files.
 *
 * weather_forecaster class is used for making url call, parsing respond and saving json into files.
 * All the data parsed is stored also in data record, but its only forecast data. To get historical
 * weather reading from file and parsing data needs to be done.
 */

/**@class weather_forecaster
 * @brief Class is used for getting and saving forecast data in files.
 *
 * weather_forecaster class is used for making url call, parsing respond and saving json into files.
 * All the data parsed is stored also in data record, but its only forecast data. To get historical
 * weather reading from file and parsing data needs to be done.
 */
class weather_forecaster : public QObject
{
    Q_OBJECT

private:
    weather_data_saver* saver; ///< Pointer to data_saver class used for saving json to files
    weather_data_caller* caller; ///< Pointer to data_caller class used for getting json from weather server
    weather_forecast_data* data; ///< Pointer to forecast_data class used for storing json objects

public:
    /**@brief Constructor
     *
     * Creates new saver, caller and data holder.
     */
    weather_forecaster();

    /**@brief Update forecast weather data.
     *
     * Makes new calls to weather server.
     * Responds are parsed in weather_forecast_data class and saved with save_data slot.
     */
    void update();

    /**@brief Data getter
     *
     * Returns pointer to forecast weather data holder.
     *
     * @return data
     */
    weather_forecast_data* get_forecast_data_ptr() const {return data;}

public slots:
    /**@brief Saves parsed data.
     *
     * Saves parsed forecast weather data in adequate files.
     * Connected to data_parsed() signal from weather_forecast_data class.
     */
    void save_data();
};




#endif //WEATHER_FORECASTER_H
