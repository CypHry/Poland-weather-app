#include "weather_MainWindow.h"

weather_MainWindow::weather_MainWindow(QMainWindow* parent) : QMainWindow(parent)
{
    Ui.setupUi(this);
    Ui.map->setScene(w_map.get_scene_ptr());
}
