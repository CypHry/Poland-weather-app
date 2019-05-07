#include "weather_forecast_data.h"


weather_forecast_data::weather_forecast_data(QObject* parent)
{
    QObject::connect(this, SIGNAL(data_parsed()), parent, SLOT(save_data()));
}


void weather_forecast_data::parse_from_string(QString answer)
{
    QJsonDocument json = QJsonDocument::fromJson(answer.toUtf8());
    QJsonObject obj = json.object();
    QJsonArray array = obj.value("list").toArray();
    QByteArray byte_array;

    QJsonDocument doc;
    for(int i = 0; i < array.size(); i++)
    {
        doc.setObject(array.at(i).toObject());
        byte_array = doc.toJson(QJsonDocument::Compact);
        std::shared_ptr<QString> temp = std::make_shared<QString>(QLatin1String(byte_array));
        json_strings.push_back(temp);
    }

    emit data_parsed();
}
