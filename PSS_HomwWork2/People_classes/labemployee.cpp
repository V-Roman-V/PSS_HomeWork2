#include "labemployee.h"
#include <sstream>

LabEmployee::LabEmployee(const People &p)
    :UniversityPeople(p)
{
    card.setAccessLevel(AccessLevel::yellow);
}

Position LabEmployee::getPosition() const
{
    return Position::lab_employee;
}

void LabEmployee::setCabinet(Cabinet *value)
{
    cabinet = value;
}

std::string LabEmployee::getFullInfo()const
{
    std::stringstream info;
    info<<UniversityPeople::getFullInfo();
    if(cabinet)
        info<<"\tCabinet: "<<cabinet->getLocation()<<std::endl;
    return info.str();
}
