#ifndef WEATHER_DATA_SAVER_H
#define WEATHER_DATA_SAVER_H

/** @file weather_data_saver.h
 *  @brief File contains  declaration of weather_data_saver class.
 */

#include "weather_data.h"
#include <QFile>

/**@brief class used for saving weather data to file
 *
 */
class weather_data_saver : public QObject
{
    Q_OBJECT

public:
    int save_data_to_file(const weather_data& data, const QString& filename);
    int save_data_to_file(const weather_data& data, QFile& file);

    /** Saving QString to file.
     *
     * Creates QFile with filename and writes string to it.
     *
     * @param string
     * @param filename
     * @retval 0 - saved successfully
     * @retval -1 - error occurred
     */
    int save_json_string_to_file(const QString& string, const QString& filename);

    /** Saving QString to file.
     *
     * @param string - string to be saved
     * @param file
     * @retval 0 - saved successfully
     * @retval -1 - error occurred
     */
    int save_json_string_to_file(const QString& string, QFile& file);
};

#endif // WEATHER_DATA_SAVER_H
