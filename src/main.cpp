#include "weather_MainWindow.h"
#include "weather_data_caller.h"
#include "weather_data_saver.h"
#include "weather_forecaster.cpp"

int main(int argc, char** argv)
{
    weather_forecaster forecaster;
    forecaster.update();
    QApplication app(argc, argv);
    weather_MainWindow main_window(nullptr);
    main_window.show();
    return app.exec();
}
