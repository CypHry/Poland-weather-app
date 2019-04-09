#ifndef WEATHER_DATA_READER_H
#define WEATHER_DATA_READER_H

#include "weather_data.h"
#include <QFile>
#include <QTextStream>

/** @file weather_data_reader.h
 *  @brief File contains  declaration of weather_data_reader class.
 */
class weather_data_reader : public QObject
{
    Q_OBJECT

public:
    /** Reads QString from file.
     *
     * @param string
     * @param filename
     * @retval 0 - read successfully
     * @retval -1 - error occurred
     */
    int read_json_string_from_file(QString& string, const QString& filename);

    /** Reads QString from file.
     *
     * @param string
     * @param file
     * @retval 0 - read successfully
     * @retval -1 - error occurred
     */
    int read_json_string_from_file(QString& string, QFile& file);

    /** Reads QString from file and parse to weather_data.
     *
     * @param data
     * @param filename
     * @retval 0 - read successfully
     * @retval -1 - error occurred
     */
    int read_data_from_file(weather_data& data, const QString& filename);

    /** Reads QString from file and parse to weather_data.
     *
     * @param data
     * @param file
     * @retval 0 - read successfully
     * @retval -1 - error occurred
     */
    int read_data_from_file(weather_data& data, QFile& file);
};



#endif // WEATHER_DATA_READER_H
