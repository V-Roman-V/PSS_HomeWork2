#include "professor.h"
#include <sstream>

Professor::Professor()
    :cabinet(nullptr)
{
    init();
}

Professor::Professor(const People &p, Cabinet* _cabinet, std::string t_course)
    :UniversityPeople(p), cabinet(_cabinet), teaching_course (t_course)
{
    init();
}

Position Professor::getPosition() const
{
    return Position::professor;
}

void Professor::setCabinet(Cabinet *value)
{
    cabinet = value;
}

std::string Professor::getFullInfo()
{
    std::stringstream info;
    info<<UniversityPeople::getCommonInfo();
    if(cabinet)
        info<<"\tCabinet: "<<cabinet->getLocation()<<std::endl;
    return info.str();
}


void Professor::init()
{
    card.setAccessLevel(AccessLevel::red);
}
