#ifndef WEATHER_CHARTS_TAB_H
#define WEATHER_CHARTS_TAB_H

#include <QObject>
#include <QChart>
#include <QChartView>
#include <QLineSeries>
#include <QDebug>
#include <QDate>
#include <QValueAxis>
#include "weather_data.h"
#include "weather_data_reader.h"

/**@file weather_charts_tab.h
 *
 * @brief File contains the declaration of weather_charts_tab class.
 * Weather_charts_tab class holds currently displayed charts in the charts tab.
 * Charts are updated after changing the data/time.
 */

/**@class weather_charts_tab
 * @brief The class holds currently displayed charts.
 *
 * Charts are updated after changing the data/time.
 */
class weather_charts_tab : public QObject
{
    Q_OBJECT

private:
    QtCharts::QChart* chart1; ///< First chart. Currently temperature chart.
    QtCharts::QChart* chart2; ///< Second chart. Currently humidity chart.
    QString current_city; ///< Record holding currently used city.
    QDate current_date; ///< Record holding currently displayed date.
    QString quantity1; ///< Record specifying which chart is currently displayed.
    QString quantity2; ///< Record specifying which chart is currently displayed.

public:
    /**@brief Constructor
     *
     * Sets the quantities to temperature and humidity and currently used city to Warsaw.
     *
     * @param parent
     */
    weather_charts_tab(QObject* parent  = nullptr);

    /**@brief The first chart getter
     *
     * @return @link weather_charts_tab::chart1 @endlink
     */
    QtCharts::QChart* get_chart1() const {return chart1;}

    /**@brief The second chart getter
     *
     * @return @link weather_charts_tab::chart2 @endlink
     */
    QtCharts::QChart* get_chart2() const {return chart2;}

private:
    /**@brief Sets new charts' series.
     *
     * Reads data from files with weather information and sets new charts' series for currently used date (@link weather_charts_tab::current_date @endlink)
     * based on @link weather_charts_tab::quantity1 @endlink and @link weather_charts_tab::quantity2 @endlink.
     */
    void set_new_series();

public slots:
    /**@brief Sets new charts' series after changing the selected city on the map of Poland.
     *
     * @param selected city
     */
    void update_data(const QString& selected_city);

    /**@brief Sets new charts' series after changing the date.
     *
     * @param new_date
     */
    void update_date(QDate new_date);

    /**@brief Sets new charts series after changing the quantity of the first chart.
    *
    * @param new_y - specifies new quantity
    */
    void update_chart1(const QString& new_y);

    /**@brief Sets new chart series after changing the quantity of the second chart.
    *
    * @param new_y - specifies new quantity
    */
    void update_chart2(const QString& new_y);
};


#endif //WEATHER_CHARTS_TAB_H
