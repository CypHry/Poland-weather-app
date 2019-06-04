#ifndef WEATHER_FORECASTER_H
#define WEATHER_FORECASTER_H

#include "weather_data_saver.h"
#include "weather_data_caller.h"
#include "weather_forecast_data.h"

/**@file weather_forecaster.h
 * @brief File contains weather_forecaster class used for getting and saving forecast data in files.
 *
 * weather_forecaster class is used for making url calls, parsing respond and saving json objects into files.
 * All the parsed data is stored also in data record. To get historical weather reading from file and parsing data needs to be done.
 */

/**@class weather_forecaster
 * @brief Class is used for getting and saving forecast data in files.
 *
 * weather_forecaster class is used for making url call, parsing respond and saving json into files.
 * All the data parsed is stored also in data record, but its only forecast data. To get historical
 * weather data reading from file and parsing data needs to be done.
 */
class weather_forecaster : public QObject
{
    Q_OBJECT

private:
    weather_data_saver* saver; ///< Pointer to the data_saver class used for saving json objects to files
    weather_data_caller* caller; ///< Pointer to the data_caller class used for getting json objects from weather server
    weather_forecast_data* data; ///< Pointer to the forecast_data class used for storing json objects

public:
    /**@brief Constructor
     *
     * Creates @link weather_forecaster::saver @endlink, @link weather_forecaster::caller @endlink and @link weather_forecaster::data @endlink.
     */
    weather_forecaster();

    /**@brief Update forecast weather data.
     *
     * Makes new calls to the weather server.
     * Responds are parsed by @link weather_forecaster::data @endlink and saved by @link weather_forecaster::saver @endlink.
     */
    void update();

    /**@brief Forecast data getter
     *
     * Returns pointer to the forecast weather data.
     *
     * @return @link weather_forecaster::data @endlink
     */
    weather_forecast_data* get_forecast_data_ptr() const {return data;}

public slots:
    /**@brief Saves parsed data.
     *
     * Saves parsed forecast weather data in adequate files.
     * Slot connected to data_parsed() signal from weather_forecast_data class.
     */
    void save_data();
};




#endif //WEATHER_FORECASTER_H
