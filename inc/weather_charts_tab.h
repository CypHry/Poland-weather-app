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
 * File contains the weather_charts_tab class.
 * Weather_charts_tab class holds currently displayed charts in the charts tab.
 * Charts are updated after changing data/time.
 * Currently the first chart is temperature chart and the second chart is humidity chart.
 */

/**@class weather_charts_tab
 * @brief The class holds currently displayed charts.
 *
 * Charts are updated after changing data/time.
 * Currently the first chart is temperature chart and the second chart is humidity chart.
 */
class weather_charts_tab : public QObject
{
    Q_OBJECT

private:
    QtCharts::QChart* temperature; ///< First chart. Currently temperature chart.
    QtCharts::QChart* humidity; ///< Second chart. Currently humidity chart.
    QString current_city; ///< Record holding currently used city.
    QDate current_date; ///< Record holding currently displayed date.

public:
    /**@brief Constructor
     *
     *
     *
     * @param parent
     */
    weather_charts_tab(QObject* parent  = nullptr);

    /**@brief temperature chart getter
     *
     * @return temperature (chart)
     */
    QtCharts::QChart* get_temperature_chart() const {return temperature;}

    /**@brief humidity chart getter
     *
     * @return humidity (chart)
     */
    QtCharts::QChart* get_humidity_chart() const {return humidity;}

private:
    /**@brief Sets new charts series.
     *
     * Reads data from files and sets new series.
     */
    void set_new_series();

public slots:
    /**@brief Sets new chart's series after changing selected city.
     *
     * @param selected city
     */
    void update_data(const QString& selected_city);

    /**@brief Sets new chart's series after changing the date.
     *
     * @param new_date
     */
    void update_date(QDate new_date);

};


#endif //WEATHER_CHARTS_TAB_H
