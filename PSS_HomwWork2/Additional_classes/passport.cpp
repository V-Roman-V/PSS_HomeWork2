#include "passport.h"

Passport::Passport(unsigned int _number, unsigned int _series)
    :number(_number), series(_series)
{}

void Passport::setPassport(unsigned int _number, unsigned int _series)
{
    number=_number;
    series=_series;
}

unsigned int Passport::getNumber() const
{
    return number;
}

unsigned int Passport::getSeries() const
{
    return series;
}

bool Passport::isCorrect()
{
    return series!=0;
}
