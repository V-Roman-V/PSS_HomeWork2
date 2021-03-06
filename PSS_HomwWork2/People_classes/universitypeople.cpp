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
    info<<"\tPersonal id: "<<card.getUniqueCode()<<std::endl;
    info<<People::getCommonInfo();
    return info.str();
}

bool UniversityPeople::tryToEnter(const Room* room)
{

}

