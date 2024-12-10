/* TeaTimer.h CS530 SDSU
main source File

Madison Bennett
id: 824800113

Alyssa Rivera
id: 825469587

Linh Tran
id: 828187432
*/

#ifndef TEA_TIMER_H
#define TEA_TIMER_H

#include <iostream>
#include <thread> //need??
#include <chrono>
#include <limits> //need??

#include "TemperatureReader.h"

//Enums
enum TeaType {BLACK, GREEN, WHITE, HERBAL, TYPE_NA};
enum TeaStrength {WEAK, MODERATE, STRONG, STRENGTH_NA};
enum  Data {TEMPATURE, TIME};

class TeaTimer
{
    public:
        static const int numTeaType = 5;//includes null values
        static const int numTeaStrength = 4;//includes null values
        static const int dataPts = 2;//Temp and time
        static const int teaData[numTeaType][numTeaStrength][dataPts];//3d array to store tea steeping data

        TeaTimer();
        void startAndExe();
        
    private:
		static const int tempTol = 1;//tolerance for tempature difference for sensor

        TeaType selTea = TYPE_NA; //to hold the selected tea type
        TeaStrength selStrength = STRENGTH_NA; // to hold the selected strength for the tea
        TemperatureReader tempReader; //to hold the temperature reader

        //String output keys
        static const std::string TeaTypeStringKey[];
        static const std::string TeaStrnStringKey[];

        //Getter functions
        TeaType getTeaType();
        TeaStrength getTeaStrength();
        int getTemp();

        //Helper Functions
        void startTimer(int timeMin);
        void soundAlarm();
        void enterToCont();

};

#endif//TEA_TIMER_H
