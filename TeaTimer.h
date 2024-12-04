/* TeaTimer.h CS530 SDSU
main source File

Madison Bennett
id: 824800113

Alyssa Rivera
id: 825469587

Linh Tran
id: 828187432
*/

#include <iostream>
#include <string>
#include "TemperatureReader.h"

enum TeaType {BLACK, GREEN, WHITE, HERBAL, TYPE_NA};
enum TeaStrength {WEAK, MODERATE, STRONG, STRENGTH_NA};
enum  Data {TEMPATURE, TIME};

class TeaTimer
{
    public:
        TeaTimer();
        void start();

        static const int numTeaType = 5;
        static const int numTeaStrength = 4;
        static const int dataPts = 2;
        static const int teaData[numTeaType][numTeaStrength][dataPts];//TODO::REMOVE MAGIC NUMBERS
        
    private:
        TeaType selTea = TYPE_NA; //to hold the selected tea type
        TeaStrength selStrength = STRENGTH_NA; // to hold the selected strength for the tea
        TemperatureReader tempReader; //to hold the temperature reader

        static const std::string TeaTypeStringKey[];
        static const std::string TeaStrnStringKey[];

        TeaType getTeaType();
        TeaStrength getTeaStrength();
        void startTimer(int timeMin);
        int getTemp();
        void soundAlarm();
        void enterToCont();

};
