#include "universitypeople.h"
#include <sstream>

UniversityPeople::UniversityPeople(const People &p)
    :People(p)
{
    card.setAccessLevel(AccessLevel::no_level);
}

std::string UniversityPeople::getCommonInfo()const
{
    std::stringstream info;
    info<<"\tPersonal id: "<<card.getUniqueCode()<<std::endl;
    info<<People::getCommonInfo();
    return info.str();
}

std::string UniversityPeople::getFullInfo()const
{
    std::stringstream info;
    info<<"\tPosition: "<<getPozitionName(getPosition())<<std::endl;
    info<<"\tAcces level: "<<getAccesLevelName(card.getAccessLevel())<<std::endl;
    info<<"\tPersonal id: "<<card.getUniqueCode()<<std::endl;
    info<<People::getCommonInfo();
    return info.str();
}

bool UniversityPeople::tryToEnter(UniversityRoom* room)
{
    if(card.getAccessLevel() < room->neededAccessLevel())
        return false;
    card.addMovemontHistory(room);
    return true;
}

void UniversityPeople::changeAccesLevel(AccessLevel level)
{
    card.setAccessLevel(level);
}

void UniversityPeople::addSpecialAccessRoom(UniversityRoom* room)
{
    special_access.push_back(room);
}

int UniversityPeople::getPersonalId() const
{
    return card.getUniqueCode();
}

std::string UniversityPeople::getPozitionName(UniversityPeople::Position p) const
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

