#include "weather_MainWindow.h"

weather_MainWindow::weather_MainWindow(QMainWindow* parent) : QMainWindow(parent)
{
    w_map = new weather_map();
    Ui.setupUi(this);
    Ui.map->setScene(w_map->get_scene_ptr());

    QObject::connect(Ui.date_edit, SIGNAL(dateChanged(QDate)), Ui.date_edit2, SLOT(setDate(QDate)));
    QObject::connect(Ui.date_edit2, SIGNAL(dateChanged(QDate)), Ui.date_edit, SLOT(setDate(QDate)));
    QObject::connect(Ui.time_edit, SIGNAL(timeChanged(QTime)), Ui.time_edit2, SLOT(setTime(QTime)));
    QObject::connect(Ui.time_edit2, SIGNAL(timeChanged(QTime)), Ui.time_edit, SLOT(setTime(QTime)));
    QObject::connect(Ui.time_edit, SIGNAL(timeChanged(QTime)), w_map, SLOT(update_time(QTime)));
    QObject::connect(Ui.date_edit, SIGNAL(dateChanged(QDate)), w_map, SLOT(update_date(QDate)));
    Ui.date_edit->setDate(QDate::currentDate());
    Ui.time_edit->setTime(QTime::currentTime());
}



