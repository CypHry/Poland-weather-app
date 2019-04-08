#include "ui_pogoda.h"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);
  QMainWindow main_window;
  Ui_MainWindow Ui;
  Ui.setupUi(&main_window);
  main_window.show();
  return app.exec();
}
