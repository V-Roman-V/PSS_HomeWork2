#include "director.h"
#include <sstream>

Director::Director(const People &p)
    :UniversityPeople(p),cabinet(nullptr)
{
    card.setAccessLevel(AccessLevel::black);
}

Position Director::getPosition() const
{
    return Position::director;
}

void Director::setCabinet(Cabinet *value)
{
    cabinet = value;
}

std::string Director::getFullInfo() const
{
    std::stringstream info;
    info<<UniversityPeople::getFullInfo();
    if(cabinet)
        info<<"\tDirector cabinet: "<<cabinet->getLocation()<<std::endl;
    return info.str();
}
