#include "weather_MainWindow.h"

weather_MainWindow::weather_MainWindow(QMainWindow* parent)
{
    this->setupUi(parent);
    map->setScene(w_map.get_scene_ptr());
}
