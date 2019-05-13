#include "weather_MainWindow.h"
#include "weather_data_caller.h"
#include "weather_data_saver.h"
#include "weather_forecaster.cpp"
#include <QChart>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    //gets weather forecast data
    weather_forecaster forecaster;
    forecaster.update();

    weather_MainWindow main_window(nullptr);
    main_window.show();

    return app.exec();
}
