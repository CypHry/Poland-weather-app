#ifndef WEATHER_CHARTS_TAB_H
#define WEATHER_CHARTS_TAB_H

#include <QObject>
#include <QChart>
#include <QChartView>
#include <QLineSeries>

class weather_charts_tab : public QObject
{
    Q_OBJECT

private:
    QtCharts::QChart* temperature;
    QtCharts::QChart* pressure;
    QtCharts::QChart* humidity;
    QtCharts::QChart* wind_speed;

public:
    weather_charts_tab(QObject* parent  = nullptr);

    QtCharts::QChart* get_temperature_chart() const {return temperature;}
    QtCharts::QChart* get_pressure_chart() const {return pressure;}
    QtCharts::QChart* get_humidity_chart() const {return humidity;}
    QtCharts::QChart* get_wind_speed_chart() const {return wind_speed;}


};


#endif //WEATHER_CHARTS_TAB_H
