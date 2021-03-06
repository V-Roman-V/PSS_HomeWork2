#include "personalcard.h"

unsigned int PersonalCard::count_card = 0;

PersonalCard::PersonalCard()
    :unique_code(PersonalCard::count_card++)
{

}

void PersonalCard::setAccessLevel(const AccessLevel &value)
{
    access_level = value;
}

const std::vector<RoomLocation> &PersonalCard::getMovementHistory() const
{
    return movement_history;
}

AccessLevel PersonalCard::getAccessLevel() const
{
    return access_level;
}

unsigned int PersonalCard::getUniqueCode() const
{
    return unique_code;
}
