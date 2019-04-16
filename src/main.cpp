#include "weather_MainWindow.h"
#include "weather_data_caller.h"
#include "weather_data_saver.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    weather_MainWindow main_window(nullptr);
    main_window.show();
    return app.exec();
}
