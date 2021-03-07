#include "student.h"
#include <sstream>

Student::Student()
    :room(nullptr)
{
    init();
}

Student::Student(const People &p, LivingRoom* lroom, unsigned short c_number)
    : UniversityPeople(p), room(lroom), course_number(c_number)
{
    init();
}

Position Student::getPosition() const
{
    return Position::student;
}

void Student::setRoom(LivingRoom *value)
{
    room = value;
}

void Student::init()
{
    card.setAccessLevel(AccessLevel::green);
}

std::string Student::getFullInfo()
{
    std::stringstream info;
    info<<UniversityPeople::getCommonInfo();
    if(room)
        info<<"\tCabinet: "<<room->getLocation()<<std::endl;
    return info.str();
}
