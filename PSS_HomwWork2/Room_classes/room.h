#ifndef ROOM_H
#define ROOM_H

#include "Additional_classes/roomlocation.h"
#include <string>

class Room
{
public:

    Room(const RoomLocation& l = RoomLocation());
    virtual ~Room() = default;
    virtual std::string getInfo();
    int getMaxPeople();
    std::string getLocation() const;

protected:
    RoomLocation room_location;
    unsigned short max_number_of_people;
};

#endif // ROOM_H
