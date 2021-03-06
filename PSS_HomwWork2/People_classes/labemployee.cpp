#include "labemployee.h"

LabEmployee::LabEmployee(const People &p)
    :UniversityPeople(p)
{
    card.setAccessLevel(AccessLevel::yellow);
}

Position LabEmployee::getPosition() const
{
    return Position::lab_employee;
}
