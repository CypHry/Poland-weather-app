#include "weather_data_caller.h"

weather_data_caller::weather_data_caller(weather_data* data_container) : QObject()
{
    QObject::connect(this, SIGNAL(answer_changed(QString)), data_container, SLOT(parse_from_string(QString)));
    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(manager_finished(QNetworkReply*)));
}

weather_data_caller::weather_data_caller(const QUrl& url, weather_data* data_container) : QObject(), request(url)
{
    QObject::connect(this, SIGNAL(answer_changed(QString)), data_container, SLOT(parse_from_string(QString)));
    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(manager_finished(QNetworkReply*)));
}

weather_data_caller::weather_data_caller(const CITY_ID city, weather_data* data_container) : QObject()
{
    QObject::connect(this, SIGNAL(answer_changed(QString)), data_container, SLOT(parse_from_string(QString)));
    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(manager_finished(QNetworkReply*)));

    switch(city)
    {
        case WARSZAWA:
            request.setUrl(QUrl("https://api.openweathermap.org/data/2.5/weather?q=Warszawa&units=metric&appid=63fe817b1ae0e5f3a6986eeecad1eb2d"));
            break;
        case WROCLAW:
            request.setUrl(QUrl("https://api.openweathermap.org/data/2.5/weather?q=Wroclaw&units=metric&appid=63fe817b1ae0e5f3a6986eeecad1eb2d"));
            break;
        case GDANSK:
            request.setUrl(QUrl("https://api.openweathermap.org/data/2.5/weather?q=Gdansk&units=metric&appid=63fe817b1ae0e5f3a6986eeecad1eb2d"));
            break;
        case KRAKOW:
            request.setUrl(QUrl("https://api.openweathermap.org/data/2.5/weather?q=Krakow&units=metric&appid=63fe817b1ae0e5f3a6986eeecad1eb2d"));
            break;
        case KATOWICE:
            request.setUrl(QUrl("https://api.openweathermap.org/data/2.5/weather?q=Katowice&units=metric&appid=63fe817b1ae0e5f3a6986eeecad1eb2d"));
            break;
        case POZNAN:
            request.setUrl(QUrl("https://api.openweathermap.org/data/2.5/weather?q=Wroclaw&units=metric&appid=63fe817b1ae0e5f3a6986eeecad1eb2d"));
            break;
        default:
            break;
    }

}

weather_data_caller::weather_data_caller(weather_forecast_data* data_container) : QObject()
{
    QObject::connect(this, SIGNAL(answer_changed(QString)), data_container, SLOT(parse_from_string(QString)));
    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(manager_finished(QNetworkReply*)));
}

weather_data_caller::weather_data_caller(const QUrl& url, weather_forecast_data* data_container) : QObject(), request(url)
{
    QObject::connect(this, SIGNAL(answer_changed(QString)), data_container, SLOT(parse_from_string(QString)));
    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(manager_finished(QNetworkReply*)));
}

weather_data_caller::weather_data_caller(const CITY_ID city, weather_forecast_data* data_container) : QObject()
{
    QObject::connect(this, SIGNAL(answer_changed(QString)), data_container, SLOT(parse_from_string(QString)));
    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(manager_finished(QNetworkReply*)));

    switch(city)
    {
        case WARSZAWA:
            request.setUrl(QUrl("https://api.openweathermap.org/data/2.5/forecast?q=Warszawa&units=metric&appid=63fe817b1ae0e5f3a6986eeecad1eb2d"));
            break;
        case WROCLAW:
            request.setUrl(QUrl("https://api.openweathermap.org/data/2.5/forecast?q=Wroclaw&units=metric&appid=63fe817b1ae0e5f3a6986eeecad1eb2d"));
            break;
        case GDANSK:
            request.setUrl(QUrl("https://api.openweathermap.org/data/2.5/forecast?q=Gdansk&units=metric&appid=63fe817b1ae0e5f3a6986eeecad1eb2d"));
            break;
        case KRAKOW:
            request.setUrl(QUrl("https://api.openweathermap.org/data/2.5/forecast?q=Krakow&units=metric&appid=63fe817b1ae0e5f3a6986eeecad1eb2d"));
            break;
        case KATOWICE:
            request.setUrl(QUrl("https://api.openweathermap.org/data/2.5/forecast?q=Katowice&units=metric&appid=63fe817b1ae0e5f3a6986eeecad1eb2d"));
            break;
        case POZNAN:
            request.setUrl(QUrl("https://api.openweathermap.org/data/2.5/forecast?q=Wroclaw&units=metric&appid=63fe817b1ae0e5f3a6986eeecad1eb2d"));
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

    this->answer = reply->readAll();
    emit answer_changed(answer);
}

void weather_data_caller::set_request_url(const QUrl& url)
{
    request.setUrl(url);
}

void weather_data_caller::get_data()
{
    manager.get(request);
}