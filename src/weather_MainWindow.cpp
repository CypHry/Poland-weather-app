#include "weather_MainWindow.h"

weather_MainWindow::weather_MainWindow(QMainWindow* parent)
{
    Ui.setupUi(parent);
    Ui.map->setScene(w_map.get_scene_ptr());
}
