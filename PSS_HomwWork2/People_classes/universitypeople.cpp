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
    info<<"\tAcces level: "<<getAccessLevel()<<std::endl;
    info<<"\tPersonal id: "<<card.getUniqueCode()<<std::endl;
    info<<People::getFullInfo();
    info<<"\tSpecial room access ("<<special_access.size()<<"):"<<std::endl;
    for(auto r: special_access)
        info<<"\t\t"<<r->getLocation()<<std::endl;


    return info.str();
}

bool UniversityPeople::isAdmin() const
{
    return false;
}

bool UniversityPeople::tryToEnter(UniversityRoom* room)
{
    for(auto sa:special_access)
        if(sa->getLocation() == room->getLocation())
            return true;
    if(card.getAccessLevel() < room->neededAccessLevel())
        return false;
    card.addMovemontHistory(room);
    return true;
}

void UniversityPeople::changeAccessLevel(AccessLevel level)
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

std::string UniversityPeople::getMovementHistory() const
{
    auto history = card.getMovementHistory();
    std::stringstream text;
    int i=0;
    for(const auto& l:history)
        text<<"\t"<<i++<<") "<<l<<std::endl;
    return text.str();
}

std::string UniversityPeople::getAccessLevel() const
{
    return getAccessLevelName(card.getAccessLevel());
}

std::string UniversityPeople::getPozitionName(const UniversityPeople::Position& p)
{
    switch (p) {
        case UniversityPeople::Position::student      :return"student";
        case UniversityPeople::Position::professor    :return"professor";
        case UniversityPeople::Position::lab_employee :return"lab_employee";
        case UniversityPeople::Position::admin        :return"admin";
        case UniversityPeople::Position::director     :return"director";
    }
    return "";
}

