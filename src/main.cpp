#include "weather_MainWindow.h"
#include "weather_data_caller.h"

int main(int argc, char** argv)
{
    weather_data data;
    weather_data_caller caller(WARSZAWA, &data);
    caller.get_data();
    QApplication app(argc, argv);
    QMainWindow main_window;
    weather_MainWindow Ui(&main_window);
    main_window.show();
    return app.exec();
}
