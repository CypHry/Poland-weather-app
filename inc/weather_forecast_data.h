#ifndef WEATHER_FORECAST_DATA_H
#define WEATHER_FORECAST_DATA_H

#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QString>
#include <QObject>
#include <memory>

/** @file weather_forecast_data.h
 *  @brief File contains  declaration of weather_forecast_data class.
 *
 *  Class weather_forecast_data parses and stores weather data from json objects (passed as QString)
 */

/**@class weather_forecast_data
 * @brief Class used for parsing and storing weather forecast data as json object.
 *
 * Class parses weather data from json objects (passed as QString) and saves them in std::vector<std::shared_ptr<QString>>.
 */
class weather_forecast_data : public QObject
{
    Q_OBJECT

private:
    std::vector<std::shared_ptr<QString>> json_strings; ///< Weather data in form of json strings.
    std::vector<std::shared_ptr<QString>> dates; ///< Forecast weather dates
    QString city; ///< Name of the currently parsed city

public:
    /** @brief Constructor
     *
     * Connects the data_parsed signal with parent's save_data slot.
     *
     * @param parent
     */
    weather_forecast_data(QObject* parent);

    /** @brief json string getter
    *
    * Returns json_strings - URL request's answer as vector of shared_ptr<QString>.
    *
    * @return @link weather_forecast_data::json_strings @endlink
    */
    const std::vector<std::shared_ptr<QString>>& get_json_strings() const {return json_strings;}

    /**@brief Dates getter
     *
     * Returns vector of all (forecast weather) dates.
     *
     * @return @link weather_forecast_data::dates @endlink
     */
    const std::vector<std::shared_ptr<QString>>& get_dates() const {return dates;}

    /**@brief City getter
     *
     * Returns the name of currently parsed city.
     *
     * @return @link weather_forecast_data::city @endlink
     */
    QString get_city() const {return city;}

public slots:
    /** @brief Parsing data from json object (passed as QString).
     *
     *  After data from the weather server answer is parsed emits data_parsed signal.
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





#endif //WEATHER_FORECAST_DATA_H
