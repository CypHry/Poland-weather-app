#ifndef WEATHER_DATA_SAVER_H
#define WEATHER_DATA_SAVER_H

/** @file weather_data_saver.h
 *  @brief File contains declaration of weather_data_saver class.
 *
 * Class weather_data_saver provides four methods for saving weather data to file.
 * You can pass weather data as a json string or weather_data class and specify file by filename or QFile parameter.
 */

#include "weather_data.h"
#include <QFile>

/**@class weather_data_saver
 * @brief Class used for saving weather data to file.
 *
 * Class provides four methods for saving weather data to file.
 * You can pass weather data as a json string or weather_data class and specify file by filename or QFile parameter.
 */
class weather_data_saver : public QObject
{
    Q_OBJECT

public:
    /** @brief Saving weather data (as weather_data class) to file specified by passed filename.
     *
     * Creates QFile with filename and saves json string from data to it.
     *
     * @param data - weather data container
     * @param filename - name of the file to be created
     * @retval 0 - saved successfully
     * @retval -1 - error occurred
     */
    int save_data_to_file(const weather_data& data, const QString& filename);

    /** Saving weather data (as weather_data class) to file.
     *
     * Gets json string from weather data container and saves it to file.
     *
     * @param data - weather data container
     * @param file - file where weather data will be saved
     * @retval 0 - saved successfully
     * @retval -1 - error occurred
     */
    int save_data_to_file(const weather_data& data, QFile& file);

    /** Saving string (weather data in form of json string) to file specified by filename.
     *
     * Creates QFile with filename and saves string to it.
     *
     * @param string - json string with weather data
     * @param filename - name of the file to be created
     * @retval 0 - saved successfully
     * @retval -1 - error occurred
     */
    int save_json_string_to_file(const QString& string, const QString& filename);

    /** Saving string (weather data in form of json string to file.
     *
     * @param string - json string with weather data
     * @param file - file where weather data will be saved
     * @retval 0 - saved successfully
     * @retval -1 - error occurred
     */
    int save_json_string_to_file(const QString& string, QFile& file);
};

#endif // WEATHER_DATA_SAVER_H
