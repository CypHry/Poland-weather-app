#include "weather_MainWindow.h"

weather_MainWindow::weather_MainWindow(QMainWindow* parent) : QMainWindow(parent)
{
    w_map = new weather_map();
    c_info = new city_info();
    charts = new weather_charts_tab(this);
    Ui.setupUi(this);
    Ui.map->setScene(w_map->get_scene_ptr());
    Ui.temperature->setChart(charts->get_temperature_chart());
    Ui.humidity->setChart(charts->get_humidity_chart());

    QObject::connect(Ui.date_edit, SIGNAL(dateChanged(QDate)), Ui.date_edit2, SLOT(setDate(QDate)));
    QObject::connect(Ui.date_edit2, SIGNAL(dateChanged(QDate)), Ui.date_edit, SLOT(setDate(QDate)));
    QObject::connect(Ui.time_edit, SIGNAL(timeChanged(QTime)), w_map, SLOT(update_time(QTime)));
    QObject::connect(Ui.date_edit, SIGNAL(dateChanged(QDate)), w_map, SLOT(update_date(QDate)));
    QObject::connect(Ui.date_edit, SIGNAL(dateChanged(QDate)), charts, SLOT(update_date(QDate)));
    QObject::connect(Ui.city_dropdown, SIGNAL(activated(const QString&)), charts, SLOT(update_data(const QString&)));
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
    c_info->set_data(selected_city->get_weather_data());
    c_info->set_city_name(selected_city->get_city_name_ptr());
    c_info->update_weather_texts();
    Ui.map->setScene(c_info->get_scene_ptr());
}