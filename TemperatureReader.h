/* TemperatureReader.h CS530 SDSU
main source File

Madison Bennett
id: 824800113

Alyssa Rivera
id: 825469587

Linh Tran
id: 828187432
*/

#ifndef TEMPERATURE_READER_H
#define TEMPERATURE_READER_H

#include <string>
#include <fstream>
#include <stdexcept>
#include <filesystem>

class TemperatureReader {
    private:
        std::string deviceFile;

        //get raw temperature data from device file
        std::string getRawTemp() const;

    public:
        explicit TemperatureReader();
        //constructor to initialize device file path
        explicit TemperatureReader(const std::string& deviceFilePath);

        //get temperature in fahrenheit
        double getTemp()const;
};

#endif // TEMPERATURE_READER_H