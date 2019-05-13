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
 *
 *  Class weather_data parses weather data from json object (passed as QString) and saves them in adequate records.
 */

/**@class weather_data
 * @brief Class used for parsing and storing weather data as well as json string - URL request's answer.
 *
 * Class parses weather data from json object (passed as QString) and saves them in adequate records.
 */
class weather_data : public QObject
{
    Q_OBJECT

private:
    QString json_string; ///< Weather data in form of json string.
    QString city_name; ///< Name of the city
    QString date; ///< Weather date
    QString description; ///< Short description of weather
    double temp; ///< Temperature in Celsius
    int pressure; ///< Pressure in hPa
    int humidity; ///< Humidity in %
    double wind_speed; ///< Wind speed in m/s
    int wind_deg; ///< Wind direction as meteorological degrees
    int clouds; ///< Cloudiness in %
    int rain; ///< Rain volume from last hour in mm
    int snow; ///< Snow volume from last hour in mm

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

    void set_city_name(const QString new_city_name) {city_name = new_city_name;}

    /** @brief date getter
     *
     * Returns date and hour of stored weather.
     * @return date
     */
    const QString& get_date() const {return date;}

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

    void notify_after_data_parsed(QObject* obj);

public slots:
    /** @brief Parsing data from QString (weather data in form of json string).
     *  After data from answer is parsed emits data_parsed signal.
     *
     *  @param answer - URL weather data server's answer.
     */
    void parse_from_string(QString answer);

signals:
    /** @brief Signal emitted after finished data parsing.
     *
     */
    void data_parsed();

};


#endif // WEATHER_DATA_H
