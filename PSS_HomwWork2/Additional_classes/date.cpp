#include "date.h"
#include <ctime>
Date::Date(unsigned short d, unsigned short m, unsigned short y)
    :year(y), month(m), day(d)
{}

unsigned short Date::getAgeDiff(const Date &r) const
{
    short diff = year - r.year - ((r.month > month)?1:((r.month == month)&&(r.day > day)));
    if(diff<0)
        diff = r.year - year - ((month > r.month)?1:((month == r.month)&&(day > r.day)));
    return diff;
}

void Date::setDate(unsigned short y, unsigned short m, unsigned short d)
{
    year = y;
    month = m;
    day = d;
}

bool Date::isCorrect() const
{
    return (year!=0);
}

Date Date::getNowDate()
{
    std::time_t t = std::time(nullptr);   // get time now
    std::tm* now = std::localtime(&t);
    Date now_date(now->tm_mday,now->tm_mon+1,(now->tm_year + 1900));
    return now_date;
}
