#include "weather_data_reader.h"

int weather_data_reader::read_json_string_from_file(QString& string, const QString& filename)
{
    QFile file(filename);
    if(file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream txt_stream(&file);
        string = txt_stream.readAll();
        return 0;
    }
    return -1;
}

int weather_data_reader::read_json_string_from_file(QString& string, QFile& file)
{
    if(file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream txt_stream(&file);
        string = txt_stream.readAll();
        return 0;
    }
    return -1;
}

int weather_data_reader::read_data_from_file(weather_data& data, const QString& filename)
{
    QFile file(filename);
    if(file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream txt_stream(&file);
        QString string = txt_stream.readAll();
        data.parse_from_string(string);
        return 0;
    }
    return -1;
}

int weather_data_reader::read_data_from_file(weather_data& data, QFile& file)
{
    if(file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream txt_stream(&file);
        QString string = txt_stream.readAll();
        data.parse_from_string(string);
        return 0;
    }
    return -1;
}

