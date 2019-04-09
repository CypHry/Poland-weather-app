#ifndef WEATHER_DATA_CALLER_H
#define WEATHER_DATA_CALLER_H


#include <QDebug>
#include <QtNetwork>
#include <QObject>
#include <weather_data.h>

/** @file weather_data_caller.h
 *  @brief File contains  declaration of weather_data_caller class and CITY enum type.
 */



/** @brief enumerated type for cities used in application
 */
enum CITY {
    WARSZAWA,
    WROCLAW,
    POZNAN,
    KRAKOW,
    KATOWICE,
    GDANSK
};

/** @brief class used for creating url requests
 *
 */

class weather_data_caller : public QObject
{

    Q_OBJECT

private:

    QNetworkAccessManager manager; /** Used for sending requests */
    QNetworkRequest request; /** Used for storing url for requests */
    QString answer; /** Used for storing request's answer */


public:
    /** @brief Constructor
     *
     * Connects answer_changed signal with data_container.
     * Connects QNetworkAccessManager's finished signal with manager_finished slot.
     *
     * @param data_container
     */
    weather_data_caller(weather_data* data_container);

    /** @brief Constructor with CITY as parameter
     *
     * Connects answer_changed signal with data_container.
     * Connects QNetworkAccessManager's finished signal with manager_finished slot.
     * Sets request's url for city's current weather.
     *
     * @param city - specifies which url to set
     * @param data_container
     */
    weather_data_caller(const CITY city, weather_data* data_container);

    /** @brief Constructor with url as parameter
     *
     * Connects answer_changed signal with data_container.
     * Connects QNetworkAccessManager's finished signal with manager_finished slot.
     * Sets request's url as passed url parameter.
     *
     * @param url
     * @param data_container
     */
    weather_data_caller(const QUrl& url, weather_data* data_container);

    /** Sets new request's url
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

    /** Prints answer to the stream.
     *
     */
    void print_answer() const {qDebug() << answer;}

    /** Returns QString contained in answer.
     *
     * @return answer
     */
    const QString get_answer() const {return answer;}

private slots:
    /** Slot for saving reply in answer variable
     *
     */
    void manager_finished(QNetworkReply* reply);

signals:
    /** Signal is emitted when the answer is updated
     *
     */
    void answer_changed(QString answer);

};


#endif // WEATHER_DATA_CALLER_H
