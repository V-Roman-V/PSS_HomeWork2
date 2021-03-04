#include "universityroom.h"

UniversityRoom::UniversityRoom()
{
}

RoomType UniversityRoom::getRoomType()
{
    return RoomType::university_room;
}

AccessLevel UniversityRoom::neededAccessLevel()
{
    return AccessLevel::no_level;
}
