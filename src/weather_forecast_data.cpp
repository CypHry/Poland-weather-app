#include "weather_forecast_data.h"


weather_forecast_data::weather_forecast_data(QObject* parent)
{
    QObject::connect(this, SIGNAL(data_parsed()), parent, SLOT(save_data()));
}


void weather_forecast_data::parse_from_string(QString answer)
{
    QJsonDocument json = QJsonDocument::fromJson(answer.toUtf8());
    QJsonObject obj = json.object();
    city = obj.value("city").toObject().value("name").toString();
    QJsonArray array = obj.value("list").toArray();
    QByteArray byte_array;

    QJsonDocument doc;
    for(int i = 0; i < array.size(); i++)
    {
        doc.setObject(array.at(i).toObject());
        byte_array = doc.toJson(QJsonDocument::Compact);
        json_strings.push_back(std::make_shared<QString>(QLatin1String(byte_array)));
        dates.push_back(std::make_shared<QString>(array.at(i).toObject().value("dt_txt").toString()));
    }

    emit data_parsed();
}
