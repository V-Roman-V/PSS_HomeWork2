#include "admin.h"

Admin::Admin(const People & p)
    :UniversityPeople(p)
{
    card.setAccessLevel(AccessLevel::red);
}

Position Admin::getPosition() const
{
    return Position::admin;
}

void Admin::giveAcces(UniversityPeople *people, Room *room)
{
//    people->
}
