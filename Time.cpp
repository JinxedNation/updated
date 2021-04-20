#include "Time.h"

Time::Time()
{
    //ctor
}

Time::Time(int temp_Hour, int temp_Minute, int temp_Second)
{
    m_The_Hour   = temp_Hour;
    m_The_Minute = temp_Minute;
    m_The_Second = temp_Second;
}


Time::~Time()
{
    //dtor
}


unsigned Time::get_The_Hour() const {return m_The_Hour;}
    void Time::set_The_Hour(unsigned temp_Hour) {m_The_Hour = temp_Hour;}


unsigned Time::get_The_Minute() const {return m_The_Minute;}
    void Time::set_The_Minute(unsigned temp_Minute) {m_The_Minute = temp_Minute;}


unsigned Time::get_The_Second() const{return m_The_Second;}
    void Time::set_The_Second() {m_The_Second = temp_Second;}







std::istream& operator >>(std::istream& input, Time& recorded_Time)
{
	unsigned temp_Hour;
	input >> temp_Hour;
	recorded_Time.set_The_Hour(temp_Hour);
	input.ignore(1);


	unsigned temp_Minute;
	input >> temp_Minute;
	recorded_Time.set_The_Minute(temp_Minute);



    unsigned temp_Seconds;
    input >> temp_Seconds;
    recorded_Time.set_The_Second(temp_Seconds);


	return input;
}





std::ostream& operator <<(std::ostream& output_s, const Time& recorded_Time)
{
	output_s << recorded_Time.get_The_Hour()   << '\n';
	output_s << recorded_Time.get_The_Minute() << '\n';
    output_s << recorded_Time.get_The_Second() << '\n';

	return output_s;
}
