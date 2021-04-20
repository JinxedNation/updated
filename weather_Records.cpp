#include "weather_Data_Reader.h"


typedef struct
{
    Date the_Date;

    Time the_Time;

    float wind_Speed;
}
WindLog_Type;


Vector <WindLog_Type> wind_Logged(100);
WindLog_Type temporary_Recorded_Wind;
std::string line_Information;


void main()
{
    std::cout << wind_Logged.get_Current_Size() << std::endl;

    std::ifstream infile("MetData-31-3.csv");
    std::ifstream infile("MetData_Mar01-2014-Mar01-2015-ALL.csv");

    if (!infile)
    {
        std::cout << "Encountered an error. Error type can not find the file." << endl;
        return;
    }


}