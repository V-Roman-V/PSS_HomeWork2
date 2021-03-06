#include "cabinet.h"

Cabinet::Cabinet(const RoomLocation &l)
    :UniversityRoom(l), worker(nullptr)
{

}

UniversityRoom::RoomType Cabinet::getRoomType() const
{
    return RoomType::cabinet;
}

AccessLevel Cabinet::neededAccessLevel()
{
    return AccessLevel::red;
}
