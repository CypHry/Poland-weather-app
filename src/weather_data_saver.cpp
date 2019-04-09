#include "weather_data_saver.h"

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
