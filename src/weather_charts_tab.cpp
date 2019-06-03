#include "weather_charts_tab.h"

weather_charts_tab::weather_charts_tab(QObject* parent) : QObject(parent)
{
    chart1 = new QtCharts::QChart();
    chart2 = new QtCharts::QChart();

    chart1->legend()->hide();
    chart2->legend()->hide();

    chart1_y = "temperature";
    chart2_y = "humidity";

    current_city = "Warsaw";
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

void weather_charts_tab::update_chart1(const QString& new_y)
{
    chart1_y = new_y;
    set_new_series();
}

void weather_charts_tab::update_chart2(const QString& new_y)
{
    chart2_y = new_y;
    set_new_series();
}

void weather_charts_tab::set_new_series()
{
    QtCharts::QLineSeries* chart1_series = new QtCharts::QLineSeries();
    QtCharts::QLineSeries* chart2_series = new QtCharts::QLineSeries();

    weather_data data;
    weather_data_reader reader;

    QString hours_str[] = {"00:00:00", "03:00:00", "06:00:00", "09:00:00", "12:00:00", "15:00:00", "18:00:00", "21:00:00"};
    int hours_int[] = {0, 3, 6, 9, 12, 15, 18, 21};
    QString filename = "weather_data/";
    filename.append(current_city);
    filename.append(" ");
    filename.append(current_date.toString("yyyy-MM-dd"));
    filename.append(" ");

    QString temp_filename;
    for(unsigned int i = 0; i < 8; i++)
    {
        temp_filename = filename;
        temp_filename.append(hours_str[i]);
        reader.read_data_from_file(data, temp_filename);
        if(chart1_y == "temperature")
            chart1_series->append(hours_int[i], data.get_temp());
        else if(chart1_y == "humidity")
            chart1_series->append(hours_int[i], data.get_humidity());
        else if(chart1_y == "pressure")
            chart1_series->append(hours_int[i], data.get_pressure());
        else if(chart1_y == "wind speed")
            chart1_series->append(hours_int[i], data.get_wind_speed());
        if(chart2_y == "temperature")
            chart2_series->append(hours_int[i], data.get_temp());
        else if(chart2_y == "humidity")
            chart2_series->append(hours_int[i], data.get_humidity());
        else if(chart2_y == "pressure")
            chart2_series->append(hours_int[i], data.get_pressure());
        else if(chart2_y == "wind speed")
            chart2_series->append(hours_int[i], data.get_wind_speed());
    }

    chart1->removeAllSeries();
    chart1->addSeries(chart1_series);
    chart1->createDefaultAxes();

    QtCharts::QValueAxis *axisX = new QtCharts::QValueAxis;
    axisX->setTitleText("Time");
    QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis;
    chart1->setAxisY(axisY, chart1_series);
    chart1->setAxisX(axisX, chart1_series);

    chart2->removeAllSeries();
    chart2->addSeries(chart2_series);
    chart2->createDefaultAxes();

    QtCharts::QValueAxis *axisX2 = new QtCharts::QValueAxis;
    axisX2->setTitleText("Time");
    QtCharts::QValueAxis *axisY2 = new QtCharts::QValueAxis;
    chart2->setAxisY(axisY2, chart2_series);
    chart2->setAxisX(axisX2, chart2_series);
}