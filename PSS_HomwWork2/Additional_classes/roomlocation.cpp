#include "roomlocation.h"

RoomLocation::RoomLocation(RoomLocation::Place building, short floor, short room_number)
    :building(building), floor(floor), room_number(room_number)
{

}

void RoomLocation::setRoomLocation(RoomLocation::Place building, short floor, short room_number)
{
    this->building = building;
    this->floor = floor;
    this->room_number = room_number;
}

short RoomLocation::getRoom_number() const
{
    return room_number;
}

short RoomLocation::getFloor() const
{
    return floor;
}

RoomLocation::Place RoomLocation::getBuilding() const
{
    return building;
}
