#include "weather_data_saver.h"
/** @file
 *
 * @brief @link weather_data_saver @endlink class source file.
 */

int weather_data_saver::save_data_to_file(const weather_data& data, const QString& filename)
{
    QString string = data.get_json_string();
    QFile file(filename);

    if(file.open(QIODevice::WriteOnly))
    {
        file.write(string.toUtf8());
        file.close();

        return 0;
    }

    return -1;
}


int weather_data_saver::save_data_to_file(const weather_data& data, QFile& file)
{
    QString string = data.get_json_string();

    if(file.open(QIODevice::WriteOnly))
    {
        file.write(string.toUtf8());
        file.close();

        return 0;
    }

    return -1;
}



int weather_data_saver::save_json_string_to_file(const QString& string, QFile& file)
{
    if(file.open(QIODevice::WriteOnly))
    {
        file.write(string.toUtf8());
        file.close();

        return 0;
    }

    return -1;
}

int weather_data_saver::save_json_string_to_file(const QString& string, const QString& filename)
{
    QFile file(filename);

    if(file.open(QIODevice::WriteOnly))
    {
        file.write(string.toUtf8());
        file.close();

        return 0;
    }

    return -1;
}
