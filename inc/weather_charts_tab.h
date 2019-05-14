#ifndef WEATHER_CHARTS_TAB_H
#define WEATHER_CHARTS_TAB_H

#include <QObject>
#include <QChart>
#include <QChartView>
#include <QLineSeries>
#include <QDebug>
#include <QDate>
#include "weather_data.h"
#include "weather_data_reader.h"

class weather_charts_tab : public QObject
{
    Q_OBJECT

private:
    QtCharts::QChart* temperature;
    QtCharts::QChart* humidity;
    QString current_city;
    QDate current_date;

public:
    weather_charts_tab(QObject* parent  = nullptr);

    QtCharts::QChart* get_temperature_chart() const {return temperature;}
    QtCharts::QChart* get_humidity_chart() const {return humidity;}

private:
    void set_new_series();

public slots:
    void update_data(const QString& selected_city);
    void update_date(QDate new_date);

};


#endif //WEATHER_CHARTS_TAB_H
