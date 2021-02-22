#ifndef UNIVERSITYROOM_H
#define UNIVERSITYROOM_H

#include "room.h"
#include "Enumerations/accesslevels.h"

using RoomType = Room::RoomType;

class UniversityRoom : public Room
{
public:
    UniversityRoom();

    virtual RoomType getRoomType() override;
private:
    AccessLevel needed_access_level;

};

#endif // UNIVERSITYROOM_H
