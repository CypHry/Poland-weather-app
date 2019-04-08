#include "weather_data_caller.h"

weather_data_caller::weather_data_caller() : QObject()
{
    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(manager_finished(QNetworkReply*)));
}

weather_data_caller::weather_data_caller(const QUrl& url) : QObject(), request(url)
{
    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(manager_finished(QNetworkReply*)));
}

weather_data_caller::weather_data_caller(const CITY city) : QObject()
{
    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(manager_finished(QNetworkReply*)));

    switch(city)
    {
        case WARSZAWA:
            request.setUrl(QUrl("https://api.openweathermap.org/data/2.5/weather?q=Warszawa&appid=63fe817b1ae0e5f3a6986eeecad1eb2d"));
            break;
        case WROCLAW:
            request.setUrl(QUrl("https://api.openweathermap.org/data/2.5/weather?q=Wroclaw&appid=63fe817b1ae0e5f3a6986eeecad1eb2d"));
            break;
        case GDANSK:
            request.setUrl(QUrl("https://api.openweathermap.org/data/2.5/weather?q=Gdansk&appid=63fe817b1ae0e5f3a6986eeecad1eb2d"));
            break;
        case KRAKOW:
            request.setUrl(QUrl("https://api.openweathermap.org/data/2.5/weather?q=Krakow&appid=63fe817b1ae0e5f3a6986eeecad1eb2d"));
            break;
        case KATOWICE:
            request.setUrl(QUrl("https://api.openweathermap.org/data/2.5/weather?q=Katowice&appid=63fe817b1ae0e5f3a6986eeecad1eb2d"));
            break;
        case POZNAN:
            request.setUrl(QUrl("https://api.openweathermap.org/data/2.5/weather?q=Wroclaw&appid=63fe817b1ae0e5f3a6986eeecad1eb2d"));
            break;
        default:
            break;
    }

}

void weather_data_caller::manager_finished(QNetworkReply *reply)
{
    if (reply->error())
    {
        qDebug() << reply->errorString();
        return;
    }

    QString answer = reply->readAll();

    qDebug() << answer;
}