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

std::string Student::getFullInfo()const
{
    std::stringstream info;
    info<<UniversityPeople::getFullInfo();
    if(room)
        info<<"\tLiving room: "<<room->getLocation()<<std::endl;
    return info.str();
}
