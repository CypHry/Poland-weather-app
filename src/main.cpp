#include "weather_MainWindow.h"
#include "weather_data_caller.h"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);
  QMainWindow main_window;
  weather_MainWindow Ui(&main_window);
  main_window.show();
  return app.exec();
}
