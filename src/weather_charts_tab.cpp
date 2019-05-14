#include "weather_charts_tab.h"

weather_charts_tab::weather_charts_tab(QObject* parent) : QObject(parent)
{
    temperature = new QtCharts::QChart();
    humidity = new QtCharts::QChart();

    temperature->legend()->hide();
    humidity->legend()->hide();
}

void weather_charts_tab::update_data(const QString& selected_city)
{
    current_city = selected_city;
    set_new_series();
}

void weather_charts_tab::update_date(QDate new_date)
{
    current_date = new_date;
    set_new_series();
}

void weather_charts_tab::set_new_series()
{
    QtCharts::QLineSeries* temperature_series = new QtCharts::QLineSeries();
    QtCharts::QLineSeries* humidity_series = new QtCharts::QLineSeries();

    temperature_series->append(0, 2);
    temperature_series->append(2, 3);
    temperature_series->append(4, 2);
    temperature_series->append(6, 4);

    temperature->removeAllSeries();
    temperature->addSeries(temperature_series);
    temperature->createDefaultAxes();

    humidity_series->append(0, 4);
    humidity_series->append(2, 6);
    humidity_series->append(4, 7);
    humidity_series->append(6, 2);

    humidity->removeAllSeries();
    humidity->addSeries(humidity_series);
    humidity->createDefaultAxes();
}