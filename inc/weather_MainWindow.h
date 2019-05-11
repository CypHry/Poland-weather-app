#ifndef WEATHER_MAINWINDOW_H
#define WEATHER_MAINWINDOW_H

#include "ui_pogoda.h"
#include "weather_map.h"
#include <QMainWindow>
#include "city_info.h"

/** @file weather_MainWindow.h
 *  @brief File contains declaration of weather_MainWindow class.
 */

/** @class weather_MainWindow
 *  @brief App's main window class
 *
 */
class weather_MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow Ui; ///< Ui class created by QtDesigner
    weather_map* w_map; ///< weather map record
    city_info* c_info;

public:
    /**@brief Constructor
     *
     * Sets Ui and graphics scene.Connects date and time edits from different tabs (map tab and chart tab).
     *
     * @param parent
     */
    weather_MainWindow(QMainWindow* parent);

    /**@brief Destructor
     *
     * Deletes w_map
     */
    ~weather_MainWindow(){delete w_map;}

public slots:
    void change_scene_to_map();
    void change_scene_to_city(std::shared_ptr<city> selected_city);

};

#endif // WEATHER_MAINWINDOW_H
