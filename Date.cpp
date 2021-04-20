#include "Date.h"

Date::Date(unsigned temp_Day, unsigned temp_Month, unsigned temp_Year)
{
    m_Day_N   = temp_Day;
    m_Month_N = temp_Month;
    m_Year_N  = temp_Year;
}

Date::Date(unsigned temp_Day, unsigned temp_Year)
{
    m_Day_N    = temp_Day;
    //m_Month_N  = temp_Month_Name;
    m_Year_N   = temp_Year;
}


Date::~Date()
{
    m_Day_N   = 0;
    m_Month_N = 0;
    m_Year_N  = 0;
}



void Date::Clear()
{
    m_Day_N      = 0;
    m_Month_N    = 0;
//    m_Month_Name   = "";
    m_Year_N     = 0;
}



unsigned Date::get_The_Day() const{return m_Day_N;}
void Date::set_The_Day(unsigned temp_Day)
{
    if(temp_Day == 0)
    {
        m_Day_N = 1;
        std::cout << "Error invalid date for day : "  << 'n/' <<"Fixing Day Date error Day is now set to default value of 1 " << std::endl;
    }
    else
        m_Day_N = temp_Day;
}



unsigned Date::get_The_Month() const {return m_Month_N;}
    void Date::set_The_Month(unsigned temp_Month) {m_Month_N = temp_Month;}



/*********************
std::string Date::get_Month_Name(){return m_Month_Name;}

void Date::set_Month_Name(std::string temp_Month_Name, const int m_Month_N)
{
    for (int i = 0; i < 12; ++i)
    {
        if(int i == m_Month_N)
        {
            std::cout << m_Month_Name[m_Month_N] << std::endl;
        }
    }
}
 ********************/


unsigned Date::get_The_Year()const {return m_Year_N;}
    void Date::set_The_Year(unsigned temp_Year) { m_Year_N = temp_Year;}





std::istream& operator >> (std::istream& input, Date& date_Recorded)
{
    unsigned temp_Day;
    input >> temp_Day;
    date_Recorded.set_The_Day(temp_Day);
    input.ignore(1);  //ignores the next char or int in the file allowing a space



    unsigned temp_Month;
    input >> temp_Month;
    date_Recorded.set_The_Month(temp_Month);
    input.ignore(1); //ignores the next char or int in the file allowing a space


    unsigned temp_Year;
    input >> temp_Year;
    date_Recorded.set_The_Year(temp_Year);


    return input;
}



std::ostream& operator <<(std::ostream &output_s, const Date &date_Recorded)
{
    output_s
        << date_Recorded.get_The_Day()   << "/"
        << date_Recorded.get_The_Month() << "/"
        << date_Recorded.get_The_Year()  << "/" ;

    return output_s;
}
