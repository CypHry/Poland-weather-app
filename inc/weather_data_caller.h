#ifndef WEATHER_DATA_CALLER_H
#define WEATHER_DATA_CALLER_H

#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QtNetwork>
#include <QObject>


enum CITY {
    WARSZAWA,
    WROCLAW,
    POZNAN,
    KRAKOW,
    KATOWICE,
    GDANSK
};

class weather_data_caller : public QObject
{

    Q_OBJECT

private:

    QNetworkAccessManager manager;
    QNetworkRequest request;


public:
    weather_data_caller();
    weather_data_caller(const CITY city);
    weather_data_caller(const QUrl& url);

private slots:
    void manager_finished(QNetworkReply* reply);

};


#endif // WEATHER_DATA_CALLER_H
