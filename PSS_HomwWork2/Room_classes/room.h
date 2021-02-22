#ifndef ROOM_H
#define ROOM_H

#include "Additional_classes/roomlocation.h"
class Room
{
public:
    enum class RoomType{living_room,university_room};

    Room();
    virtual ~Room() = default;
    virtual RoomType getRoomType() = 0;

private:
    RoomLocation room_location;
    unsigned short max_number_of_people;
};

#endif // ROOM_H
