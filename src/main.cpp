#include "ui_pogoda.h"
#include "weather_MainWindow.h"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);
  QMainWindow main_window;
  weather_MainWindow Ui(&main_window);
  main_window.show();
  return app.exec();
}
