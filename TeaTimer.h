/* TeaTimer.h CS530 SDSU
main source File

Madison Bennett
id: 824800113

... add yours



*/

#include <unistd.h>
#include <iostream>

enum TeaType {BLACK, GREEN, WHITE, HERBAL, TYPE_NA};
enum TeaStrength {WEAK, MODERATE, STRONG, STRENGTH_NA};
enum  Data {TEMPATURE, TIME};

class TeaTimer
{
    public:
        void start();


        static const int numTeaType = 4;
        static const int numTeaStrength = 3;
        static const int teaData[numTeaType][numTeaStrength][2];//TODO::REMOVE MAGIC NUMBERS
        
    private:
        TeaType selTea; //to hold the selected tea type
        TeaStrength selStrength; // to hold the selected strength for the tea

        TeaType getTeaType();
        TeaStrength getTeaStrength();
        void startTimer(int time);
        int getTemp();
        void soundAlarm();
        void enterToCont();

};