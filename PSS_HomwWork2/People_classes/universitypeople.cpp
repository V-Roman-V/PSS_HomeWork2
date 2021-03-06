#include "universitypeople.h"
#include <sstream>

UniversityPeople::UniversityPeople(const People &p)
    :People(p)
{
    card.setAccessLevel(AccessLevel::no_level);
}

std::string UniversityPeople::getCommonInfo()
{
    std::stringstream info;
    info<<"\tPersonal id: "<<card.getUniqueCode()<<std::endl;
    info<<People::getCommonInfo();
    return info.str();
}

std::string UniversityPeople::getFullInfo()
{
    std::stringstream info;
    info<<"\tPosition: "<<getPozitionName(getPosition())<<std::endl;
    info<<"\tPersonal id: "<<card.getUniqueCode()<<std::endl;
    info<<"\tAcces level: "<<getAccesLevelName(card.getAccessLevel())<<std::endl;
    info<<People::getCommonInfo();
    return info.str();
}

bool UniversityPeople::tryToEnter(const Room* room)
{
    //    return false;
}

std::string UniversityPeople::getPozitionName(UniversityPeople::Position p)
{
    switch (p) {
        case UniversityPeople::Position::student      :return"student";
        case UniversityPeople::Position::professor    :return"professor";
        case UniversityPeople::Position::lab_employee :return"lab employee";
        case UniversityPeople::Position::admin        :return"admin";
        case UniversityPeople::Position::director     :return"director";
    }
    return "";
}

