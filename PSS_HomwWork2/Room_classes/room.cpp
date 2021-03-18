#include "room.h"
#include <sstream>

Room::Room(const RoomLocation &l)
    :room_location(l)
{

}

std::string Room::getInfo()
{
    std::stringstream info;
    info<<"\tRoom location: "<<room_location<<std::endl;
    info<<"\tRoom capacity: "<<max_number_of_people<<std::endl;
    return info.str();
}

int Room::getMaxPeople()
{
    return max_number_of_people;
}

std::string Room::getLocation() const
{
    std::stringstream info;
    info<<room_location;
    return info.str();
}
