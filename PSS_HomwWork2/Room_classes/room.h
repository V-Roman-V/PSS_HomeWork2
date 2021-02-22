#ifndef ROOM_H
#define ROOM_H

#include "Enumerations/roomtype.h"
#include "Additional_classes/roomlocation.h"
class Room
{
public:
    Room();
    virtual ~Room() = default;
    virtual RoomType getRoomType() = 0;

private:
    RoomLocation room_location;
    unsigned short max_number_of_people;
};

#endif // ROOM_H
