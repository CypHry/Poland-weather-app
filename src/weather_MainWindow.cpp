#include "weather_MainWindow.h"

weather_MainWindow::weather_MainWindow(QMainWindow* parent) : QMainWindow(parent)
{
    w_map = new weather_map();
    c_info = new city_info();
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

    QObject::connect(c_info, SIGNAL(change_scene()), this, SLOT(change_scene_to_map()));
    QObject::connect(w_map, SIGNAL(change_scene(std::shared_ptr<city>)), this, SLOT(change_scene_to_city(std::shared_ptr<city>)));
}



void weather_MainWindow::change_scene_to_map()
{
    w_map->get_scene_ptr()->clearSelection();
    Ui.map->setScene(w_map->get_scene_ptr());
}

void weather_MainWindow::change_scene_to_city(std::shared_ptr<city> selected_city)
{
    c_info->get_scene_ptr()->clearSelection();
    Ui.map->setScene(c_info->get_scene_ptr());
}