#include "weather_MainWindow.h"

weather_MainWindow::weather_MainWindow(QMainWindow* parent) : QMainWindow(parent)
{
    Ui.setupUi(this);
    Ui.map->setScene(w_map.get_scene_ptr());

    QObject::connect(Ui.date_edit, SIGNAL(dateChanged(QDate)), Ui.date_edit2, SLOT(setDate(QDate)));
    QObject::connect(Ui.date_edit2, SIGNAL(dateChanged(QDate)), Ui.date_edit, SLOT(setDate(QDate)));
    QObject::connect(Ui.time_edit, SIGNAL(timeChanged(QTime)), Ui.time_edit2, SLOT(setTime(QTime)));
    QObject::connect(Ui.time_edit2, SIGNAL(timeChanged(QTime)), Ui.time_edit, SLOT(setTime(QTime)));
}
