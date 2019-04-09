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
    /** city_name getter
     *
     * @return city_name
     */
    const QString& get_city_name() const {return city_name;}

    /** date getter
     *
     * @return date
     */
    const QString& get_date() const {return date;}

    /** hour getter
     *
     * @return hour
     */
    const QString& get_hour() const {return hour;}

    /** description getter
     *
     * @return description
     */
    const QString& get_description() const {return description;}

    /** temperature getter
     *
     * @return temp
     */
    const double& get_temp() const {return temp;}

    /** pressure getter
     *
     * @return pressure
     */
    const int& get_pressure() const {return pressure;}

    /** humidity getter
     *
     * @return humidity
     */
    const int& get_humidity() const {return humidity;}

    /** wind_speed getter
     *
     * @return wind_speed
     */
    const double& get_wind_speed() const {return wind_speed;}

    /** wind_deg getter
     *
     * @return wind_deg
     */
    const int& get_wind_deg() const {return wind_deg;}

    /** clouds getter (in %)
     *
     * @return clouds
     */
    const int& get_clouds() const {return clouds;}

    /** rain getter
     *
     * @return rain
     */
    const int& get_rain() const {return rain;}

    /** snow getter
     *
     * @return snow
     */
    const int& get_snow() const {return snow;}

public slots:
    /** Parsing data from QString
     *
     */
    void parse_from_string(QString answer);

};


#endif // WEATHER_DATA_H
