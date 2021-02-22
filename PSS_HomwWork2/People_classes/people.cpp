#include "people.h"

People::People()
{

}

std::string People::getInfo()
{

}

std::string People::getName() const
{
    return name;
}

void People::setName(const std::string &value)
{
    name = value;
}

Date People::getDateOfBirth() const
{
    return date_of_birth;
}

void People::setDateOfBirth(const Date &value)
{
    date_of_birth = value;
}

Passport People::getPassport() const
{
    return passport;
}

void People::setPassport(const Passport &value)
{
    passport = value;
}

unsigned short People::getAge() const
{
//    return date_of_birth;
    return 0;
}

Gender People::getGender() const
{
    return gender;
}

void People::setGender(const Gender &value)
{
    gender = value;
}

std::string People::getNationality() const
{
    return nationality;
}

void People::setNationality(const std::string &value)
{
    nationality = value;
}
