#include "conferenceroom.h"

ConferenceRoom::ConferenceRoom(const RoomLocation &l, unsigned short max_people)
    :UniversityRoom(l)
{
    myAccessLevel = AccessLevel::blue;
    max_number_of_people = max_people;
}

UniversityRoom::RoomType ConferenceRoom::getRoomType() const
{
    return RoomType::conference_room;
}

std::string ConferenceRoom::getNeededLevel()
{
    return getAccessLevelName(AccessLevel::blue);
}
