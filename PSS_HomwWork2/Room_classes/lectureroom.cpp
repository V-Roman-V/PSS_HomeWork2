#include "lectureroom.h"

LectureRoom::LectureRoom(const RoomLocation &l)
    :UniversityRoom(l)
{

}

UniversityRoom::RoomType LectureRoom::getRoomType() const
{
    return RoomType::lecture_room;
}

AccessLevel LectureRoom::neededAccessLevel()
{
    return AccessLevel::yellow;
}
