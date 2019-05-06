#include "weather_forecast_data.h"


weather_forecast_data::weather_forecast_data(QObject* parent)
{
    QObject::connect(this, SIGNAL(data_parsed()), parent, SLOT(save_data()));
}


void weather_forecast_data::parse_from_string(QString answer)
{
    emit data_parsed();
}

