#ifndef LIVINGROOM_H
#define LIVINGROOM_H

#include "room.h"
#include <vector>
#include <People_classes/people.h>

class LivingRoom : public Room
{
public:
    LivingRoom(const RoomLocation& l = RoomLocation(),unsigned short max_people = 2);

private:
//    std::vector<People*> residents;
    unsigned short current_number_of_people;
};

#endif // LIVINGROOM_H
