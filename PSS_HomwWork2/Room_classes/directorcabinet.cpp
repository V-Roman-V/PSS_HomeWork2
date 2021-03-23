#include "directorcabinet.h"

DirectorCabinet::DirectorCabinet(const RoomLocation &l)
    : Cabinet(l)
{
    myAccessLevel = AccessLevel::black;
    max_number_of_people = 1;
}

UniversityRoom::RoomType DirectorCabinet::getRoomType() const
{
    return RoomType::director_cabinet;
}

std::string DirectorCabinet::getNeededLevel()
{
    return getAccessLevelName(AccessLevel::black);
}

void DirectorCabinet::addWorker(Director *d)
{
    workers.push_back(d);
    d->setCabinet(this);
}
