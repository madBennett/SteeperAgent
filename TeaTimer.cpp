/* TeaTimer.cpp CS530 SDSU
main source File

Madison Bennett
id: 824800113

Alyssa Rivera
id: 825469587

... addd yours



*/

#include "TeaTimer.h"
#include <thread>
#include <chrono>
#include <limits>
#include <filesystem>



//map arrays
const int TeaTimer::teaData[numTeaType][numTeaStrength][3] = {     //TODO::REMOVE MAGIC NUMBERS
    {{/*Weak*/ 200, 3}, {/*Moderate*/ 206, 4}, {/*Strong*/ 212, 5}}, //Black
    {{/*Weak*/ 140, 1}, {/*Moderate*/ 163, 2}, {/*Strong*/ 185, 3}}, //Green
    {{/*Weak*/ 160, 1}, {/*Moderate*/ 167, 2}, {/*Strong*/ 185, 3}}, //White
    {{/*Weak*/ 200, 5}, {/*Moderate*/ 200, 6}, {/*Strong*/ 200, 7}}, //Herbal
    {{/*Weak*/ 80, 1}, {/*Moderate*/ 80, 1}, {/*Strong*/ 80, 1}} //Test
};

void TeaTimer::start()
{
    //initialize temperature sensor
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

    const std::string deviceFile = deviceFolder + "/w1_slave";

    tempReader = TemperatureReader(deviceFile);

    selTea = getTeaType();
    selStrength = getTeaStrength();


    // get data for tea
    int steepTemp = teaData[selTea][selStrength][TEMPATURE];
    int steepTime = teaData[selTea][selStrength][TIME];

    //wait for temp to be in range for steeping
    double currentTemp = tempReader.getTemp();
    while (currentTemp < steepTemp)
    {
        //waiting
        std::cout << "Waiting for water to reach " << steepTemp << " degrees F\n" 
            << "Current Temp: " << currentTemp << " degrees F" << std::endl;
        sleep(1);
        system("clear");
        currentTemp = tempReader.getTemp();
    }
    
    soundAlarm();

    std::cout << "Please insert Tea..." << std::endl;
    enterToCont();

    startTimer(steepTime);

    soundAlarm();
    
    std::cout << "Please remove tea bag.  Your tea is ready, enjoy!!!" << std::endl;
    enterToCont();
    
}

TeaType TeaTimer::getTeaType()
{
    //
    //get tea type
    TeaType tTyp;
    int i = 0;
    do
    {
        system("clear");
        std::cout << "Select Tea type\n\t1. Black \n\t2. Green \n\t3. White \n\t4.Herbal \n\t5.Quit \n->";
        std::cin >> i;

        if (i >= 1 || i <= numTeaType)
        {
            tTyp = (TeaType)(i - 1);
        }
    } while (i <= 0 || i > 5);

    system("clear");
    return tTyp;
}

TeaStrength TeaTimer::getTeaStrength()
{
    //
    //get tea strength
    TeaStrength tStren;
    int i = 0;
    do
    {
        system("clear");
        std::cout << "Select Tea Strength\n\t1. Weak \n\t2. Moderate \n\t3. Strong \n\t4. Quit \n->";
        std::cin >> i;

        if (i >= 1 || i < numTeaStrength)
        {
            tStren = (TeaStrength)(i - 1);
        }
    } while (i <= 0 || i > 4);

    system("clear");
    return tStren;
}

void TeaTimer::startTimer(int timeMin)
{
    //
    std::cout << "Tea is steeping..." << std::endl;
    sleep(timeMin * 60);
}

void TeaTimer::soundAlarm()
{
    //
    //sound alarm for 2 seconds
    system("speaker-test -t sine -f 1000 -l 1 & sleep 2 && kill -9 $!");
    enterToCont();
}

void TeaTimer::enterToCont()
{
    //
    std::cout << "Press enter to continue ..." << std::endl;
    std::cin.ignore();
    system("clear");
}