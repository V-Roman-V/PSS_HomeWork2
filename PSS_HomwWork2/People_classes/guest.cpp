#include "guest.h"

Guest::Guest(const People &p)
    : UniversityPeople(p)
{
    init();
}

void Guest::init()
{
    card.setAccessLevel(AccessLevel::blue);
}

Position Guest::getPosition() const
{
    return Position::guest;
}
