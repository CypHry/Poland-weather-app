#ifndef WEATHER_DATA_READER_H
#define WEATHER_DATA_READER_H

#include "weather_data.h"
#include <QFile>
#include <QTextStream>

/** @file weather_data_reader.h
 *  @brief File contains  declaration of weather_data_reader class.
 *
 *  Class weather_data_reader is used from reading weather data from files.
 *  It reads QString (weather data in form of json string) from specified file and passes it to weather_data for parsing.
 */

/**@class weather_data_reader
 * @brief Class used for reading weather data from files.
 *
 * Reads QString (weather data in form of json string) from specified file and passes it to weather_data for parsing.
 */
class weather_data_reader : public QObject
{
    Q_OBJECT

public:
    /** Reads QString (weather data in form of json string) from file and parse with weather_data.
     *
     * Weather data read from file is contained in data (weather_data passed as parameter).
     *
     * @param data - weather data container and parser
     * @param filename - name of the file from which data is read
     * @retval 0 - read successfully
     * @retval -1 - error occurred
     */
    int read_data_from_file(weather_data& data, const QString& filename);

    /** Reads QString (weather data in form of json string) from file and parse to weather_data.
     *
     * Weather data read from file is contained in data (weather_data passed as parameter).
     *
     * @param data - weather data container and parser
     * @param file - file from which data is read
     * @retval 0 - read successfully
     * @retval -1 - error occurred
     */
    int read_data_from_file(weather_data& data, QFile& file);
};



#endif // WEATHER_DATA_READER_H
