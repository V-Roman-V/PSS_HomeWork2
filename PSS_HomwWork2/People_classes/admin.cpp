#include "admin.h"

Admin::Admin(const People & p, std::string password)
    :UniversityPeople(p), password(password)
{
    card.setAccessLevel(AccessLevel::red);
}

Position Admin::getPosition() const
{
    return Position::admin;
}

bool Admin::isAdmin() const
{
    return true;
}

void Admin::giveAccess(UniversityPeople *people, UniversityRoom *room)
{
    people->addSpecialAccessRoom(room);
}

void Admin::giveAccess(UniversityPeople *people, AccessLevel level)
{
    people->changeAccessLevel(level);
}

bool Admin::checkPassword(const std::string &pass)
{
    return (password.compare(pass) == 0);
}
