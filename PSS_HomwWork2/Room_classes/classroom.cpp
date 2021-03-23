#include "classroom.h"

ClassRoom::ClassRoom(const RoomLocation &l)
    :UniversityRoom(l)
{
    myAccessLevel = AccessLevel::green;
    max_number_of_people = 25;
}

UniversityRoom::RoomType ClassRoom::getRoomType() const
{
    return RoomType::class_room;
}

std::string ClassRoom::getNeededLevel()
{
    return getAccessLevelName(AccessLevel::green);
}
