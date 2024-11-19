/* TeaTimer.cpp CS530 SDSU
main source File

Madison Bennett
id: 824800113

Alyssa Rivera
id: 825469587

... addd yours



*/

#include "TeaTimer.h"
#include <OneWire.h>
#include <DallasTemperature.h>
//map arrays
const int TeaTimer::teaData[numTeaType][numTeaStrength][2] = {     //TODO::REMOVE MAGIC NUMBERS
    {{/*Weak*/ 200, 3}, {/*Moderate*/ 206, 4}, {/*Strong*/ 212, 5}}, //Black
    {{/*Weak*/ 140, 1}, {/*Moderate*/ 163, 2}, {/*Strong*/ 185, 3}}, //Green
    {{/*Weak*/ 160, 1}, {/*Moderate*/ 167, 2}, {/*Strong*/ 185, 3}}, //White
    {{/*Weak*/ 200, 5}, {/*Moderate*/ 200, 6}, {/*Strong*/ 200, 7}}, //Herbal
};

void TeaTimer::start()
{
    //initialize temperature sensor
    //connect data wire to pin 4 on Arduino
    const int oneWireBus = 4;
    //setup oneWire instance
    OneWire oneWire(oneWireBus);
    //pass oneWire ref to Dallas Temp sensor
    DallasTemperature sensors(&oneWire);

    //initialize monitor and sensor
    Serial.begin(9600);
    sensors.begin();

    selTea = getTeaType();
    selStrength = getTeaStrength();


    // get data for tea
    int steepTemp = teaData[selTea][selStrength][TEMPATURE];
    int steepTime = teaData[selTea][selStrength][TIME];

    //wait for temp to be in range for steeping
    while (getTemp() < steepTemp)
    {
        //waiting
        std::cout << "Waiting for water to reach " << steepTemp << " degrees F\n" 
            << "Current Temp: " << getTemp() << " degrees F" << std::endl;
        sleep(1);
        system("clear");
        break;
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

int TeaTimer::getTemp()
{
    //call request temp method before getting val
    sensors.requestTemperatures();

    //get temperature in fahrenheit
    float currTemp = sensors.getTempFByIndex(0);
    delay(5000);
    return -1;
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