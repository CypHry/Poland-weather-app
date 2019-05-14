#ifndef WEATHER_CHARTS_TAB_H
#define WEATHER_CHARTS_TAB_H

#include <QObject>
#include <QChart>
#include <QChartView>

class weather_charts_tab : public QObject
{
    Q_OBJECT

private:
    QtCharts::QChart temperature;
    QtCharts::QChart pressure;
    QtCharts::QChart humidity;
    QtCharts::QChart wind_speed;

public:
    weather_charts_tab(QObject* parent = nullptr) : QObject(parent) {};
};


#endif //WEATHER_CHARTS_TAB_H
