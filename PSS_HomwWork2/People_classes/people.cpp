#include "people.h"

People::People(const std::string &_name, const std::string& _surname, const People::Gender &_gender, const Date &_date_of_birth, const Passport &_passport, const std::string &_phone_number, const std::string &_nationality)
    :name(_name),surname(_surname), date_of_birth(_date_of_birth), passport(_passport), gender(_gender), phone_number(_phone_number), nationality(_nationality)
{

}

void People::setPeople(const std::string &_name,const std::string& _surname, const People::Gender &_gender, const Date &_date_of_birth, const Passport &_passport, const std::string &_phone_number, const std::string &_nationality)
{
    name          = _name;
    surname       = _surname;
    date_of_birth = _date_of_birth;
    passport      = _passport;
    gender        = _gender;
    phone_number  = _phone_number;
    nationality   = _nationality;
}

std::string People::getInfo()
{
    return "";
}

std::string People::getName() const
{
    return name;
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
    Date cur_date(2021,02,23);
    return date_of_birth.getAgeDiff(cur_date);
}

People::Gender People::getGender() const
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

std::string People::getPhoneNumber() const
{
    return phone_number;
}

void People::setPhoneNumber(const std::string &value)
{
    phone_number = value;
}
