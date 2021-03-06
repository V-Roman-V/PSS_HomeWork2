#include "conferenceroom.h"

ConferenceRoom::ConferenceRoom(const RoomLocation &l)
    :UniversityRoom(l)
{

}

UniversityRoom::RoomType ConferenceRoom::getRoomType() const
{
    return RoomType::conference_room;
}

AccessLevel ConferenceRoom::neededAccessLevel()
{
    return AccessLevel::red;
}
