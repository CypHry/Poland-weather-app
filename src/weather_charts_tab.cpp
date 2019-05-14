#include "weather_charts_tab.h"

weather_charts_tab::weather_charts_tab(QObject* parent) : QObject(parent)
{
    temperature = new QtCharts::QChart();
    pressure = new QtCharts::QChart();
    humidity = new QtCharts::QChart();
    wind_speed = new QtCharts::QChart();

    QtCharts::QLineSeries* temp_series = new QtCharts::QLineSeries();

    temp_series->append(0, 6);
    temp_series->append(2, 4);
    temp_series->append(3, 8);
    temp_series->append(7, 4);
    temp_series->append(10, 5);

    temperature->addSeries(temp_series);
    temperature->legend()->hide();
    temperature->createDefaultAxes();

    QtCharts::QLineSeries* pressure_series = new QtCharts::QLineSeries();
    pressure_series->append(0, 6);
    pressure_series->append(2, 4);
    pressure_series->append(3, 8);
    pressure_series->append(7, 4);
    pressure_series->append(10, 5);
    pressure->addSeries(pressure_series);
    pressure->legend()->hide();
    pressure->createDefaultAxes();

    //humidity->addSeries(series);
    humidity->legend()->hide();
    humidity->createDefaultAxes();

    //wind_speed->addSeries(series);
    wind_speed->legend()->hide();
    wind_speed->createDefaultAxes();
}
