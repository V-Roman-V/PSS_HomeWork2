#include "student.h"

Student::Student()
{
    card->setAccessLevel(AccessLevel::green);
}

Position Student::getPosition() const
{
    return Position::student;
}
