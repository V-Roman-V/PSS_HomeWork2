#include "date.h"

Date::Date(unsigned short y, unsigned short m, unsigned short d)
    :year(y), month(m), day(d)
{}

int Date::getAgeDiff(const Date &r) const
{
    int diff = year - r.year - ((r.month > month)?1:((r.month == month)&&(r.day > day)));
    return (diff>0)?diff:0;
}

void Date::setDate(unsigned short y, unsigned short m, unsigned short d)
{
    year = y;
    month = m;
    day = d;
}
