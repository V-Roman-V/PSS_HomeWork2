#include "directorcabinet.h"

DirectorCabinet::DirectorCabinet(const RoomLocation &l)
    : Cabinet(l)
{

}

UniversityRoom::RoomType DirectorCabinet::getRoomType() const
{
    return RoomType::director_cabinet;
}

AccessLevel DirectorCabinet::neededAccessLevel()
{
    return AccessLevel::black;
}
