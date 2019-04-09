#ifndef WEATHER_DATA_CALLER_H
#define WEATHER_DATA_CALLER_H


#include <QDebug>
#include <QtNetwork>
#include <QObject>
#include <weather_data.h>

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
    QString answer;


public:
    weather_data_caller(weather_data* data_container);
    weather_data_caller(const CITY city, weather_data* data_container);
    weather_data_caller(const QUrl& url, weather_data* data_container);

    void set_request_url(const QUrl& url);
    void get_data();
    void print_answer() {qDebug() << answer;}
    const QString get_answer() {return answer;}

private slots:
    void manager_finished(QNetworkReply* reply);

signals:
    void answer_changed(QString answer);

};


#endif // WEATHER_DATA_CALLER_H
