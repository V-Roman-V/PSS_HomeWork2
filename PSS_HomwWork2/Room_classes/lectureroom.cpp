#include "lectureroom.h"

LectureRoom::LectureRoom(const RoomLocation &l, unsigned short max_people)
    :UniversityRoom(l)
{
    myAccessLevel = AccessLevel::yellow;
    max_number_of_people = max_people;
}

UniversityRoom::RoomType LectureRoom::getRoomType() const
{
    return RoomType::lecture_room;
}

std::string LectureRoom::getNeededLevel()
{
    return getAccessLevelName(AccessLevel::yellow);
}
