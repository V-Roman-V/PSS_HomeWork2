#ifndef LIVINGROOM_H
#define LIVINGROOM_H

#include "room.h"
#include <vector>
#include <People_classes/people.h>

using RoomType = Room::RoomType;

class LivingRoom : public Room
{
public:
    LivingRoom();
    virtual RoomType getRoomType() override;

private:
    std::vector<People*> residents;
    unsigned short current_number_of_people;
};

#endif // LIVINGROOM_H
