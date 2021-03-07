#include "lectureroom.h"

LectureRoom::LectureRoom(const RoomLocation &l, unsigned short max_people)
    :UniversityRoom(l)
{
    max_number_of_people = max_people;
}

UniversityRoom::RoomType LectureRoom::getRoomType() const
{
    return RoomType::lecture_room;
}

AccessLevel LectureRoom::neededAccessLevel()
{
    return AccessLevel::yellow;
}
