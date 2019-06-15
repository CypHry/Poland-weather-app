#ifndef WEATHER_MAINWINDOW_H
#define WEATHER_MAINWINDOW_H

#include "ui_pogoda.h"
#include "weather_map.h"
#include <QMainWindow>
#include "city_info.h"
#include "weather_charts_tab.h"

/** @file weather_MainWindow.h
 *  @brief File contains the declaration of weather_MainWindow class.
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
    weather_map* w_map; ///< Weather map scene and it's data
    city_info* c_info; ///< City info scene and it's data
    weather_charts_tab* charts; ///< Charts tab

public:
    /**@brief Constructor
     *
     * Sets Ui and graphics scenes for the map of Poland and the view with information about the selected city.
     * Connects date and time edits from different tabs.
     *
     * @param parent
     */
    weather_MainWindow(QMainWindow* parent);

    /**@brief Destructor
     *
     * Deletes @link weather_MainWindow::w_map @endlink and @link weather_MainWindow::c_info @endlink.
     */
    ~weather_MainWindow(){delete w_map; delete c_info;}

public slots:

    /**@brief Updates city info after selecting new city on the map of Poland.
     *
     * City info is parsed from selected city param.
     *
     * @param selected_city
     */
    void update_cityinfo(std::shared_ptr<city> selected_city);

    /**@brief Emits stop/start animations signal depending on the passed state.
     *
     * @param state
     */
    void animations_checkbox_change(int state);

signals:
    /**@brief Signal emitted after unchecking the animations check box.
     *
     */
    void stop_animations();

    /**@brief Signal emitted after checking the animations check box.
     *
     */
    void start_animations();

};

#endif // WEATHER_MAINWINDOW_H
