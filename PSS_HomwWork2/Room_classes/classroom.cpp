#include "classroom.h"

ClassRoom::ClassRoom(const RoomLocation &l)
    :UniversityRoom(l)
{
    max_number_of_people = 25;
}

UniversityRoom::RoomType ClassRoom::getRoomType() const
{
    return RoomType::class_room;
}

AccessLevel ClassRoom::neededAccessLevel()const
{
    return AccessLevel::green;
}
