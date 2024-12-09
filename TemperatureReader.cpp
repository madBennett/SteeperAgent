/* TemperatureReader.cpp CS530 SDSU
main source File

Madison Bennett
id: 824800113

Alyssa Rivera
id: 825469587

Linh Tran
id: 828187432
*/

#include "TemperatureReader.h"

TemperatureReader::TemperatureReader()
{
    //Constructor to initialize temperature sensor
    //para: n/a
    //returns: n/a
    
    //connect data wire 
    const std::string baseDir = "/sys/bus/w1/devices/";
    std::string deviceFolder;

    for (const auto& entry : std::filesystem::directory_iterator(baseDir)) {
        if (entry.is_directory() && entry.path().string().find("28-") != std::string::npos) {
            deviceFolder = entry.path().string();
            break;
        }
    }

    if (deviceFolder.empty()) {
        throw std::runtime_error("Unable to find temperature sensor");
    }

    deviceFile = deviceFolder + "/w1_slave";
}

TemperatureReader::TemperatureReader(const std::string& deviceFilePath) : deviceFile(deviceFilePath) {}

std::string TemperatureReader::getRawTemp() const 
{
    //Function to read the tempature sensors data with out processing it
    //para: n/a
    //returns: n/a

    //get device file
    std::ifstream file(deviceFile);
    //check if file opened successfully
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open device file " + deviceFile);
    }

    std::string lines;
    std::string line;

    while (std::getline(file, line)) {
        lines += line + "\n";
    }
    //close file and return lines
    file.close();
    return lines;
}

double TemperatureReader::getTemp() const 
{
    //Function to process the tempature sensors raw data 
    //para: n/a
    //returns: n/a

    std::string lines;

    do {
        lines = getRawTemp();
    } while (lines.find("YES") == std::string::npos);

    size_t equals_pos = lines.find("t=");
    if (equals_pos != std::string::npos) {
        std::string temp_string = lines.substr(equals_pos + 2);
        double temp_c = std::stod(temp_string) / 1000.0; //get temp in celsius
        double temp_f = temp_c * 9.0 / 5.0 + 32.0; //convert to fahrenheit
        return temp_f; //return temperature
    }

    throw std::runtime_error("Temp data not found in file");
}
