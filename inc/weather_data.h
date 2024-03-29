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
    QString main; ///< Main weather condition
    double temp; ///< Temperature in Celsius
    double pressure; ///< Pressure in hPa
    int humidity; ///< Humidity in %
    double wind_speed; ///< Wind speed in m/s
    double wind_deg; ///< Wind direction as meteorological degrees
    int clouds; ///< Cloudiness in %
    int rain; ///< Rain volume from last hour in mm
    int snow; ///< Snow volume from last hour in mm

public:
    /** @brief Constructor
     *
     * Connects data_parsed signal with parent's set_weather_text slot.
     * @param parent
     */
    weather_data(QObject* parent = nullptr);


    /** @brief city_name getter
     *
     * Returns city name.
     * @return @link weather_data::city_name @endlink
     */
    const QString& get_city_name() const {return city_name;}

    /**@brief City name setter
     *
     * Sets new city name. Used after parsing json without name of the city.
     *
     * @param new_city_name
     */
    void set_city_name(const QString new_city_name) {city_name = new_city_name;}

    /** @brief date getter
     *
     * Returns date and hour of stored weather.
     * @return @link weather_data::date @endlink
     */
    const QString& get_date() const {return date;}

    /** @brief description getter
     *
     * Returns description of main weather condition.
     *
     * @return @link weather_data::description @endlink
     */
    const QString& get_description() const {return description;}

    /** @brief main weather condition
    *
    * Returns the main weather condition.
    *
    * @return @link weather_data::main @endlink
    */
    const QString& get_main() const {return main;}

    /** @brief temperature getter
     *
     * Returns temperature (Celsius)
     *
     * @return @link weather_data::temp @endlink
     */
    const double& get_temp() const {return temp;}

    /** @brief pressure getter
     *
     * Returns atmospheric pressure (hPa).
     *
     * @return @link weather_data::pressure @endlink
     */
    const double& get_pressure() const {return pressure;}

    /** @brief humidity getter
     *
     * Returns humidity (%).
     *
     * @return @link weather_data::humidity @endlink
     */
    const int& get_humidity() const {return humidity;}

    /** @brief wind_speed getter
     *
     * Returns wind speed (m/s).
     *
     * @return @link weather_data::wind_speed @endlink
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
     * @return @link weather_data::wind_deg @endlink
     */
    const double& get_wind_deg() const {return wind_deg;}

    /** @brief clouds getter
     *
     * Returns cloudiness (%).
     *
     * @return @link weather_data::clouds @endlink
     */
    const int& get_clouds() const {return clouds;}

    /** @brief rain getter
     *
     * Returns rain volume from last hour (mm).
     *
     * @return @link weather_data::rain @endlink
     */
    const int& get_rain() const {return rain;}

    /** @brief snow getter
     *
     * Returns snow volume from last hour (mm).
     *
     * @return @link weather_data::snow @endlink
     */
    const int& get_snow() const {return snow;}

    /** @brief json string getter
     *
     * Returns json_string - URL request's answer.
     *
     * @return @link weather_data::json_string @endlink
     */
    const QString& get_json_string() const {return json_string;}

    /**@brief Connects data_parsed signal with obj update_parsed_data slot.
     *
     * @param obj
     */
    void notify_after_data_parsed(QObject* obj);

public slots:
    /** @brief Parse data from QString (weather data in form of json string).
     *
     *  After data from the weather server's answer is parsed emits data_parsed signal.
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
