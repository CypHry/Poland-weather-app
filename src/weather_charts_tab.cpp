#include "weather_charts_tab.h"

weather_charts_tab::weather_charts_tab(QObject* parent) : QObject(parent)
{
    temperature = new QtCharts::QChart();
    humidity = new QtCharts::QChart();

    temperature->legend()->hide();
    humidity->legend()->hide();

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

void weather_charts_tab::set_new_series()
{
    QtCharts::QLineSeries* temperature_series = new QtCharts::QLineSeries();
    QtCharts::QLineSeries* humidity_series = new QtCharts::QLineSeries();

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
        temperature_series->append(hours_int[i], data.get_temp());
        humidity_series->append(hours_int[i], data.get_humidity());
    }

    temperature->removeAllSeries();
    temperature->addSeries(temperature_series);
    temperature->createDefaultAxes();

    QtCharts::QValueAxis *axisX = new QtCharts::QValueAxis;
    axisX->setTitleText("Time");
    QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis;
    axisY->setTitleText("Temperature");
    temperature->setAxisY(axisY, temperature_series);
    temperature->setAxisX(axisX, temperature_series);

    humidity->removeAllSeries();
    humidity->addSeries(humidity_series);
    humidity->createDefaultAxes();

    QtCharts::QValueAxis *axisX2 = new QtCharts::QValueAxis;
    axisX2->setTitleText("Time");
    QtCharts::QValueAxis *axisY2 = new QtCharts::QValueAxis;
    axisY2->setTitleText("Humidity");
    humidity->setAxisY(axisY2, humidity_series);
    humidity->setAxisX(axisX2, humidity_series);
}