#include "livingroom.h"

LivingRoom::LivingRoom(const RoomLocation &l, unsigned short max_people)
    :Room(l)
{
    max_number_of_people = max_people;
}

