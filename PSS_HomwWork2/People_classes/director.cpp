#include "director.h"

Director::Director(const People &p)
    :UniversityPeople(p)
{
    card.setAccessLevel(AccessLevel::black);
}

Position Director::getPosition() const
{
    return Position::director;
}
