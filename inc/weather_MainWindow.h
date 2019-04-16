#ifndef WEATHER_MAINWINDOW_H
#define WEATHER_MAINWINDOW_H

#include "ui_pogoda.h"
#include "weather_map.h"

/** @file weather_data.h
 *  @brief File contains  declaration of weather_data class.
 */

class weather_MainWindow
{
private:
    Ui::MainWindow Ui;
    weather_map w_map;

public:
    weather_MainWindow(QMainWindow* parent);
};

#endif // WEATHER_MAINWINDOW_H
