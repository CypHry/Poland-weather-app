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
 * @brief Class used for saving weather data to files.
 *
 * Class provides four methods for saving weather data to files.
 * You can pass weather data as a json string or weather_data class and specify file by filename (as QString) or QFile parameter.
 */
class weather_data_saver : public QObject
{
    Q_OBJECT

public:
    /** @brief Saving weather data to file specified by passed filename.
     *
     * Creates QFile with passed filename and saves json string with weather data to the created file.
     *
     * @param data - weather data container
     * @param filename - name of the file to be created
     * @retval 0 - saved successfully
     * @retval -1 - error occurred
     */
    int save_data_to_file(const weather_data& data, const QString& filename);

    /** Saving weather data to file.
     *
     * Gets json string from weather data container and saves weather data to the file.
     *
     * @param data - weather data container
     * @param file - file where weather data will be saved
     * @retval 0 - saved successfully
     * @retval -1 - error occurred
     */
    int save_data_to_file(const weather_data& data, QFile& file);

    /** Saving string (weather data in form of json string) to file specified by passed filename.
     *
     * Creates QFile with passed filename and saves weather data to the created file.
     *
     * @param string - json string with weather data
     * @param filename - name of the file to be created
     * @retval 0 - saved successfully
     * @retval -1 - error occurred
     */
    int save_json_string_to_file(const QString& string, const QString& filename);

    /** Saving string (weather data in form of json string) to the file.
     *
     * @param string - json string with weather data
     * @param file - file where weather data will be saved
     * @retval 0 - saved successfully
     * @retval -1 - error occurred
     */
    int save_json_string_to_file(const QString& string, QFile& file);
};

#endif // WEATHER_DATA_SAVER_H
