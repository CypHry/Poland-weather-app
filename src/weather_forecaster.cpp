#include "weather_forecaster.h"


weather_forecaster::weather_forecaster()
{
    data = new weather_data();
    caller = new weather_data_caller(data);
    saver = new weather_data_saver();
}
