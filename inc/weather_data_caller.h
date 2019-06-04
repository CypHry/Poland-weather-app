#ifndef WEATHER_DATA_CALLER_H
#define WEATHER_DATA_CALLER_H


#include <QDebug>
#include <QtNetwork>
#include <QObject>
#include "weather_data.h"
#include "weather_forecast_data.h"

/** @file weather_data_caller.h
 *  @brief File contains  declaration of weather_data_caller class and CITY_ID enum type.
 *
 *  Class weather_data_caller connects with weather data container (weather_data class) during creation.
 *  After sending request to server weather_data caller emits signal with answer to the connected data container.
 *
 *  CITY_ID enumerated type contains all the ids of the cities used in the app.
 */


/** @brief Enumerated type for cities currently used in application.
 */
enum CITY_ID {
    WARSZAWA,
    WROCLAW,
    POZNAN,
    KRAKOW,
    KATOWICE,
    GDANSK
};

#define NUMBER_OF_CITIES 6 ///< Number of cities currently used in application.

/**@class weather_data_caller
 * @brief Class used for creating and sending url requests to the weather server.
 *
 * Connects with weather data container (weather_data class) during creation.
 * After sending request to server weather_data_caller emits signal with answer to the connected data container.
 */
class weather_data_caller : public QObject
{

    Q_OBJECT

private:

    QNetworkAccessManager manager; ///< Used for sending requests
    QNetworkRequest request; ///< Used for storing a url for requests
    QString answer; ///< Used for storing an answer from server


public:
    /** @brief Constructor
     *
     * Connects answer_changed signal with the data_container's parse_from string slot.
     * Connects QNetworkAccessManager's finished signal with manager_finished slot.
     *
     * @param data_container
     */
    weather_data_caller(weather_data* data_container);

    /** @brief Constructor with CITY ID as parameter
     *
     * Connects answer_changed signal with the data_container's parse_from_string slot.
     * Connects QNetworkAccessManager's finished signal with manager_finished slot.
     * Sets request's url for city's current weather.
     *
     * @param city - specifies which url to set
     * @param data_container - place where weather data will be held
     */
    weather_data_caller(const CITY_ID city, weather_data* data_container);

    /** @brief Constructor with url as parameter
     *
     * Connects answer_changed signal with the data_container's parse_from_string slot.
     * Connects QNetworkAccessManager's finished signal with manager_finished slot.
     * Sets request's url as passed url parameter.
     *
     * @param url - url address for sending requests
     * @param data_container - place where weather data will be held
     */
    weather_data_caller(const QUrl& url, weather_data* data_container);

    /** @brief Constructor
     *
     * Connects answer_changed signal with the data_container's parse_from_string slot.
     * Connects QNetworkAccessManager's finished signal with manager_finished slot.
     *
     * @param data_container
     */
    weather_data_caller(weather_forecast_data* data_container);

    /** @brief Constructor with CITY as parameter
     *
     * Connects answer_changed signal with the data_container's parse_from_string slot.
     * Connects QNetworkAccessManager's finished signal with manager_finished slot.
     * Sets request's url for city's current weather.
     *
     * @param city - specifies which url to set
     * @param data_container - place where weather data will be held
     */
    weather_data_caller(const CITY_ID city, weather_forecast_data* data_container);

    /** @brief Constructor with url as parameter
     *
     * Connects answer_changed signal with data_container.
     * Connects QNetworkAccessManager's finished signal with manager_finished slot.
     * Sets request's url as passed url parameter.
     *
     * @param url - url address for sending requests
     * @param data_container - place where weather data will be contained
     */
    weather_data_caller(const QUrl& url, weather_forecast_data* data_container);

    /** @brief Sets new request's url
     *
     * @param url - new request's url
     */
    void set_request_url(const QUrl& url);

    /** @brief Sends url requests.
     *
     *  Request's url needs to be set before calling this function.
     *  Signal QNetworkAccessManager's finished signal is emitted to manager_finished slot.
     */
    void get_data();

    /** @brief Prints answer to the qDebug stream (standard output).
     *
     */
    void print_answer() const {qDebug() << answer;}

    /** @brief answer getter.
     *
     * Returns URL request's answer.
     * @return @link weather_data_caller::answer @endlink
     */
    const QString get_answer() const {return answer;}

private slots:
    /** @brief Slot for saving reply from the weather server in @link weather_data_caller::answer @endlink.
     *
     */
    void manager_finished(QNetworkReply* reply);

signals:
    /** @brief Signal emitted when the answer is changed (after sending new request and receiving answer).
     *
     */
    void answer_changed(QString answer);

};


#endif // WEATHER_DATA_CALLER_H
