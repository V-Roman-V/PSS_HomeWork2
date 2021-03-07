#include "directorcabinet.h"

DirectorCabinet::DirectorCabinet(const RoomLocation &l)
    : Cabinet(l)
{
    max_number_of_people = 5;
}

UniversityRoom::RoomType DirectorCabinet::getRoomType() const
{
    return RoomType::director_cabinet;
}

AccessLevel DirectorCabinet::neededAccessLevel()const
{
    return AccessLevel::black;
}
