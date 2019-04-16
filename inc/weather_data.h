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

/**@class Class used for parsing and storing weather data as well as json string - URL request's answer.
 *
 */
class weather_data : public QObject
{
    Q_OBJECT

private:
    QString json_string;
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

    /** @brief Constructor
     *
     * Connects data_parsed signal with parent's set_weather_text slot.
     *
     * @param parent
     */
    weather_data(QObject* parent);


    /** @brief city_name getter
     *
     * Returns city name.
     * @return city_name
     */
    const QString& get_city_name() const {return city_name;}

    /** @brief date getter
     *
     * Returns date of stored weather.
     * @return date
     */
    const QString& get_date() const {return date;}

    /** @brief hour getter
     *
     *  Returns hour of stored weather.
     * @return hour
     */
    const QString& get_hour() const {return hour;}

    /** @brief description getter
     *
     * Returns description of main weather condition.
     *
     * @return description
     */
    const QString& get_description() const {return description;}

    /** @brief temperature getter
     *
     * Returns temperature (Celsius)
     *
     * @return temp
     */
    const double& get_temp() const {return temp;}

    /** @brief pressure getter
     *
     * Returns atmospheric pressure (hPa).
     *
     * @return pressure
     */
    const int& get_pressure() const {return pressure;}

    /** @brief humidity getter
     *
     * Returns humidity (%).
     *
     * @return humidity
     */
    const int& get_humidity() const {return humidity;}

    /** @brief wind_speed getter
     *
     * Returns wind speed (m/s).
     *
     * @return wind_speed
     */
    const double& get_wind_speed() const {return wind_speed;}

    /** @brief wind_deg getter
     *
     * Returns meteorological wind direction (degrees).
     * north wind - 0 degrees
     * south wind - 90 degrees
     * east wind - 180 degrees
     * west wind - 270 degrees
     *
     * @return wind_deg
     */
    const int& get_wind_deg() const {return wind_deg;}

    /** @brief clouds getter
     *
     * Returns cloudiness (%).
     *
     * @return clouds
     */
    const int& get_clouds() const {return clouds;}

    /** @brief rain getter
     *
     * Returns rain volume from last hour (mm).
     *
     * @return rain
     */
    const int& get_rain() const {return rain;}

    /** @brief snow getter
     *
     * Returns snow volume from last hour (mm).
     *
     * @return snow
     */
    const int& get_snow() const {return snow;}

    /** @brief json string getter
     *
     * Returns json_string - URL request's answer.
     *
     * @return json_string
     */
    const QString& get_json_string() const {return json_string;}

public slots:
    /** @brief Parsing data from QString.
     *  After data from answer is parsed emits data_parsed signal.
     *
     *  @param answer - URL request's answer.
     */
    void parse_from_string(QString answer);

signals:
    /** @biref Signal emitted after data parsing
     *
     */
    void data_parsed();

};


#endif // WEATHER_DATA_H
