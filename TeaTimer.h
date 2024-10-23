/* TeaTimer.h CS530 SDSU
main source File

Madison Bennett
id: 824800113

... add yours



*/

#include <unistd.h>
#include <iostream>

enum TeaType {BLACK, GREEN, WHITE, HERBAL};
enum TeaStrength {WEAK, MODERATE, STRONG};
enum  Data {TEMPATURE, TIME};

class TeaTimer
{
    public:
        TeaTimer();
        void start();


        static const int numTeaType = 4;
        static const int teaData[numTeaType][3][2];//TODO::REMOVE MAGIC NUMBERS
        
    private:
        TeaType selTea; //to hold the selected tea type
        TeaStrength selStrength; // to hold the selected strength for the tea

        TeaType getTeaType();
        void startTimer();
        int getTemp();

};