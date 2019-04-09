#ifndef WEATHER_DATA_H
#define WEATHER_DATA_H

#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QString>
#include <QObject>

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

public:
    int save_to_file();
    void read_from_file();

public slots:
    void parse_from_string(QString answer);

};


#endif // WEATHER_DATA_H
