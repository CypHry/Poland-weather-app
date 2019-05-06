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


class weather_forecast_data : public QObject
{
    Q_OBJECT

private:
    std::vector<QString> json_strings; ///< Weather data in form of json string.

public:
    /** @brief Constructor
     *
     * Connects data_parsed signal with parent's save_data slot.
     *
     * @param parent
     */
    weather_forecast_data(QObject* parent);

    /** @brief json string getter
    *
    * Returns json_string - URL request's answer.
    *
    * @return json_string
    */
    const std::vector<QString>& get_json_strings() const {return json_strings;}

public slots:
    /** @brief Parsing data from QString (weather data in form of json strings).
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





#endif //WEATHER_FORECAST_DATA_H
