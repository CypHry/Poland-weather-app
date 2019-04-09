#ifndef WEATHER_DATA_SAVER_H
#define WEATHER_DATA_SAVER_H

/** @file weather_data_saver.h
 *  @brief File contains  declaration of weather_data_saver class.
 */

#include "weather_data.h"
#include <QFile>


class weather_data_saver : public QObject
{
    Q_OBJECT

public:
    int save_to_file(const weather_data& data, const QString& filename);
    int save_to_file(const weather_data& data, QFile& file);
};

#endif // WEATHER_DATA_SAVER_H
