/* TeaTimer.cpp CS530 SDSU
main source File

Madison Bennett
id: 824800113

Alyssa Rivera
id: 825469587

Linh Tran
id: 828187432
*/

#include "TeaTimer.h"

//map arrays
const int TeaTimer::teaData[numTeaType][numTeaStrength][dataPts] = {     
    {{/*Weak*/ 200, 3}, {/*Moderate*/ 206, 4}, {/*Strong*/ 212, 5}}, //Black
    {{/*Weak*/ 140, 1}, {/*Moderate*/ 163, 2}, {/*Strong*/ 185, 3}}, //Green
    {{/*Weak*/ 160, 1}, {/*Moderate*/ 167, 2}, {/*Strong*/ 185, 3}}, //White
    {{/*Weak*/ 200, 5}, {/*Moderate*/ 200, 6}, {/*Strong*/ 200, 7}}, //Herbal
    {{/*Weak*/ 0, 0}, {/*Moderate*/ 0, 0}, {/*Strong*/ 0, 0}} //Null  
};

const std::string TeaTimer::TeaTypeStringKey[] = {"Black", "Green", "White", "Herbal", ""};
const std::string TeaTimer::TeaStrnStringKey[] = {"Weak", "Moderate", "Strong", ""};

TeaTimer::TeaTimer()
{
    selTea = TYPE_NA; 
    selStrength = STRENGTH_NA;
    tempReader = TemperatureReader();
}

void TeaTimer::startAndExe()
{
    //Function to start and exicute the steeper agent
    //para: n/a
    //returns: n/a

    // get tea type and strength
    selTea = getTeaType();
    selStrength = getTeaStrength();

    // get data for tea
    int steepTemp = teaData[selTea][selStrength][TEMPATURE];
    int steepTime = teaData[selTea][selStrength][TIME];

    //Display data
    std::cout << "Tea Data\n" << "\tTea Type: " << TeaTypeStringKey[selTea] 
        << "\n\tTea Strength: " << TeaStrnStringKey[selStrength] << "\n\t\tSteep Time: " << steepTime << " minutes"
        << "\n\t\tSteep Temp: " << steepTemp << " degrees F\n" 
        "Please insert Tempature sensor" << std::endl;
    enterToCont();

    //wait for temp to be in range for steeping
    double currentTemp = tempReader.getTemp();
    while ((currentTemp < steepTemp - tempTol) || (currentTemp > steepTemp + tempTol))
    {
        //waiting
        std::cout << "Waiting for water to reach steeping tempature" << std::endl;
        std::cout << "Current Temp: " << currentTemp << " degrees F" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");
        currentTemp = tempReader.getTemp();
    }
    
    // alert user that water is ready; prompt user with further instructions
    soundAlarm();

    std::cout << "Please remove sensor and insert Tea." << std::endl;
    enterToCont();
    
    std::cout << "Tea is steeping..." << std::endl;
    startTimer(steepTime);

    // alert user that tea is ready; prompt with further instructions
    soundAlarm();
    
    system("clear");
    std::cout << "Please remove tea bag.  Your tea is ready, enjoy!!!" << std::endl;
    enterToCont();
}

TeaType TeaTimer::getTeaType()
{
    //Function to create menu and get the users tea type
    //para: n/a
    //returns: Selected tea type

    //get tea type
    TeaType tTyp;
    int i = 0;
    do
    {
        //prompt user to select tea type
        system("clear");
        std::cout << "Select Tea type\n\t1. Black \n\t2. Green \n\t3. White \n\t4. Herbal \n\t5. Quit \n->";
        std::cin >> i;

        //quit if user selects 5
        if (i == 5)
        {
            std::exit(1);
        }

        //teaType selected
        if (i >= 1 || i <= numTeaType)
        {
            tTyp = (TeaType)(i - 1);//Scheme to match index of enum
        }
    } while (i <= 0 || i > numTeaType);

    system("clear");
    return tTyp;
}

TeaStrength TeaTimer::getTeaStrength()
{
    //Function to create menu and get the users tea stregnth
    //para: n/a
    //returns: Selected tea strength

    //get tea strength
    TeaStrength tStren;
    int i = 0;
    do
    {
        //prompt user to select tea strength
        system("clear");
        std::cout << "Select Tea Strength\n\t1. Weak \n\t2. Moderate \n\t3. Strong \n\t4. Quit \n->";
        std::cin >> i;

        //quit if user selects 4
        if (i == 4)
        {
            std::exit(1);
        }

        //Get tea strength
        if (i >= 1 || i <= numTeaStrength)
        {
            tStren = (TeaStrength)(i - 1);//Scheme to match index of enum
        }
    } while (i <= 0 || i > numTeaStrength);

    system("clear");
    return tStren;
}

void TeaTimer::startTimer(int timeMin)
{
    //Function to start a timer
    //para: n/a
    //returns: N/a
    std::this_thread::sleep_for(std::chrono::seconds(timeMin * 60));
}

void TeaTimer::soundAlarm()
{
    //Function to play beep for 2 seconds
    //para: n/a
    //returns: n/a

    //sound alarm for 2 seconds
    system("speaker-test -t sine -f 1000 -l 1 & sleep 2 && kill -9 $! > /dev/null 2>&1");
    system("clear");
}

void TeaTimer::enterToCont()
{
    //Function to display text as intermediary
    //para: n/a
    //returns: N/a

    std::cout << "Press enter to continue ..." << std::endl;
    std::cin.ignore();
    std::cin.ignore();
    system("clear");
}
