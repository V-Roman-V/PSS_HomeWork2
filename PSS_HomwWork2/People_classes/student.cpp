#include "student.h"

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

void Student::init()
{
    card.setAccessLevel(AccessLevel::green);
}
