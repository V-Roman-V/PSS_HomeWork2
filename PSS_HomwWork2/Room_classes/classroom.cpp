#include "classroom.h"

ClassRoom::ClassRoom(const RoomLocation &l)
    :UniversityRoom(l)
{

}

UniversityRoom::RoomType ClassRoom::getRoomType() const
{
    return RoomType::class_room;
}

AccessLevel ClassRoom::neededAccessLevel()
{
    return AccessLevel::green;
}
