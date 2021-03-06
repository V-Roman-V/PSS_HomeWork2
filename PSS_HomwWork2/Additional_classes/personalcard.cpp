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

int PersonalCard::getAccessLevel() const
{
    switch(access_level){
        case AccessLevel::no_level:return 0;
        case AccessLevel::green:   return 1;
        case AccessLevel::yellow:  return 2;
        case AccessLevel::red:     return 3;
        case AccessLevel::black:   return 4;
    }
    return 0;
}

unsigned int PersonalCard::getUniqueCode() const
{
    return unique_code;
}
