#ifndef WEATHER_MAINWINDOW_H
#define WEATHER_MAINWINDOW_H

#include "ui_pogoda.h"
#include "weather_map.h"
#include <QMainWindow>

/** @file weather_MainWindow.h
 *  @brief File contains declaration of weather_MainWindow class.
 */

/** @class weather_MainWindow
 *  @brief App's main window class
 *
 */
class weather_MainWindow : public QMainWindow
{
private:
    Ui::MainWindow Ui;
    weather_map w_map;

public:
    /**@brief Constructor
     *
     * Sets Ui and graphics scene.Connects date and time edits from different tabs (map tab and chart tab).
     *
     * @param parent
     */
    weather_MainWindow(QMainWindow* parent);
};

#endif // WEATHER_MAINWINDOW_H
