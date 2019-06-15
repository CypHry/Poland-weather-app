#include "weather_MainWindow.h"


/** @file
 *
 * @brief @link weather_MainWindow @endlink class source file.
 */

weather_MainWindow::weather_MainWindow(QMainWindow* parent) : QMainWindow(parent)
{
    w_map = new weather_map();
    c_info = new city_info();
    charts = new weather_charts_tab(this);
    Ui.setupUi(this);
    Ui.map->setScene(w_map->get_scene_ptr());
    Ui.temperature->setChart(charts->get_chart1());
    Ui.humidity->setChart(charts->get_chart2());

    QObject::connect(Ui.date_edit, SIGNAL(dateChanged(QDate)), Ui.date_edit2, SLOT(setDate(QDate)));
    QObject::connect(Ui.date_edit2, SIGNAL(dateChanged(QDate)), Ui.date_edit, SLOT(setDate(QDate)));
    QObject::connect(Ui.time_edit, SIGNAL(timeChanged(QTime)), w_map, SLOT(update_time(QTime)));
    QObject::connect(Ui.date_edit, SIGNAL(dateChanged(QDate)), w_map, SLOT(update_date(QDate)));
    QObject::connect(Ui.date_edit, SIGNAL(dateChanged(QDate)), charts, SLOT(update_date(QDate)));
    QObject::connect(Ui.city_dropdown, SIGNAL(activated(const QString&)), charts, SLOT(update_data(const QString&)));
    QObject::connect(Ui.chart1_dropdown, SIGNAL(activated(const QString&)), charts, SLOT(update_chart1(const QString&)));
    QObject::connect(Ui.chart2_dropdown, SIGNAL(activated(const QString&)), charts, SLOT(update_chart2(const QString&)));
    QObject::connect(Ui.animations_checkBox, SIGNAL(stateChanged(int)), this, SLOT(animations_checkbox_change(int)));
    QObject::connect(this, SIGNAL(start_animations()), w_map, SLOT(start_animations()));
    QObject::connect(this, SIGNAL(stop_animations()), w_map, SLOT(stop_animations()));


    Ui.date_edit->setDate(QDate::currentDate());
    Ui.time_edit->setTime(QTime::currentTime());

    QObject::connect(w_map, SIGNAL(city_selected(std::shared_ptr<city>)), this, SLOT(update_cityinfo(std::shared_ptr<city>)));
}

void weather_MainWindow::update_cityinfo(std::shared_ptr<city> selected_city)
{
    c_info->get_scene_ptr()->clearSelection();
    c_info->set_data(selected_city->get_weather_data());
    c_info->set_city_name(selected_city->get_city_name_ptr());
    c_info->update_weather_texts();
    Ui.cityinfo->setScene(c_info->get_scene_ptr());
}

void weather_MainWindow::animations_checkbox_change(int state)
{
    if(state == Qt::Checked)
        emit start_animations();
    else
        emit stop_animations();
}
