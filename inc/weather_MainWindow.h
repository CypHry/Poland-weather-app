#ifndef WEATHER_MAINWINDOW_H
#define WEATHER_MAINWINDOW_H

#include "ui_pogoda.h"
#include "weather_map.h"

/** @file weather_MainWindow.h
 *  @brief File contains declaration of weather_MainWindow class.
 */

/** App's main window class
 *
 */
class weather_MainWindow
{
private:
    Ui::MainWindow Ui;
    weather_map w_map;

public:
    /**Constructor
     *
     * Sets Ui and graphics scene.
     *
     * @param parent
     */
    weather_MainWindow(QMainWindow* parent);
};

#endif // WEATHER_MAINWINDOW_H
