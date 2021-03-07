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

void Admin::giveAcces(UniversityPeople *people, UniversityRoom *room)
{
    people->addSpecialAccessRoom(room);
}

void Admin::giveAcces(UniversityPeople *people, AccessLevel level)
{
    people->changeAccesLevel(level);
}
