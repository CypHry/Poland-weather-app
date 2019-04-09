#ifndef WEATHER_DATA_H
#define WEATHER_DATA_H

#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QString>
#include <QObject>

/** @file weather_data.h
 *  @brief File contains  declaration of weather_data class.
 */

/**@brief class used for storing weather data
 *
 */
class weather_data : public QObject
{
    Q_OBJECT

private:
    QString city_name;
    QString date;
    QString hour;
    QString description;
    double temp;
    int pressure;
    int humidity;
    double wind_speed;
    int wind_deg;
    int clouds;
    int rain;
    int snow;

public:
    /** Saving weather data to file.
     *
     * @retval 0 if saved successfully
     * @retval -1 if error occurred
     */
    int save_to_file() const;

    /** Reading weather data from file.
     *
     */
    void read_from_file();

public slots:
    /** Parsing data from QString
     *
     */
    void parse_from_string(QString answer);

};


#endif // WEATHER_DATA_H
