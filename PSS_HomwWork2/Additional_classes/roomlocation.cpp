#include "roomlocation.h"

RoomLocation::RoomLocation(RoomLocation::Place building, short floor, short room_number, short campuse_num)
    :building(building), floor(floor), room_number(room_number), campuse_number(campuse_num)
{

}

void RoomLocation::setRoomLocation(RoomLocation::Place building, short floor, short room_number,short campuse_num)
{
    this->building = building;
    this->floor = floor;
    this->room_number = room_number;
    this->campuse_number = campuse_num;
}

std::ostream& operator<<(std::ostream& os, const RoomLocation& l){
    switch (l.building) {
        case RoomLocation::Place::university:os<<"University, ";break;
        case RoomLocation::Place::campuse:os<<"Campuse "<<l.campuse_number<<", ";break;
    }
    return os<<l.floor<<" floor, n:"<<l.room_number;
}
