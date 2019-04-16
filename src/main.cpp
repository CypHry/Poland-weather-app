#include "weather_MainWindow.h"
#include "weather_data_caller.h"
#include "weather_data_saver.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QMainWindow main_window;
    weather_MainWindow ui(&main_window);
    main_window.show();
    return app.exec();
}
