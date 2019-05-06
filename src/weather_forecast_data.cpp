#include "weather_forecast_data.h"


weather_forecast_data::weather_forecast_data(QObject* parent)
{
    QObject::connect(this, SIGNAL(data_parsed()), parent, SLOT(save_data()));
}