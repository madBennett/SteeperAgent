/* TeaTimer.cpp CS530 SDSU
main source File

Madison Bennett
id: 824800113

... addd yours



*/

#include "TeaTimer.h"

//map arrays
const int TeaTimer::teaData[4][3][2] = {                              //TODO::REMOVE MAGIC NUMBERS
    {{/*Weak*/ 200, 3}, {/*Moderate*/ 206, 4}, {/*Strong*/ 212, 5}}, //Black
    {{/*Weak*/ 140, 1}, {/*Moderate*/ 163, 2}, {/*Strong*/ 185, 3}}, //Green
    {{/*Weak*/ 160, 1}, {/*Moderate*/ 167, 2}, {/*Strong*/ 185, 3}}, //White
    {{/*Weak*/ 200, 5}, {/*Moderate*/ 200, 6}, {/*Strong*/ 200, 7}}, //Herbal
};

TeaTimer::TeaTimer()
{
    //
}

void TeaTimer::start()
{
    //

    //get tea type
    int i = 0;
    do
    {
        
        std::cout << "Select Tea type\n\t1. Black \n\t2. Green \n\t3. White \n\t4.Herbal \n\t 5.Quit \n->";
        std::cin >> i;

        if (i >= 1 || i <= 4)
        {
            selTea = (TeaType)(i - 1);
        }
        

    } while (i <= 0 || i > 5);
}

TeaType TeaTimer::getTeaType()
{
    //
    return BLACK;
}

void TeaTimer::startTimer()
{
    //
}

int TeaTimer::getTemp()
{
    //
    return -1;
}