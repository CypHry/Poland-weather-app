#ifndef WEATHER_MAINWINDOW_H
#define WEATHER_MAINWINDOW_H

#include "ui_pogoda.h"
#include "weather_map.h"


class weather_MainWindow : protected Ui::MainWindow
{
private:
    weather_map map;

public:
    weather_MainWindow(QMainWindow* parent);
};

#endif // WEATHER_MAINWINDOW_H
