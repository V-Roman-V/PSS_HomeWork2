#ifndef UNIVERSITYROOM_H
#define UNIVERSITYROOM_H

#include "room.h"
#include "Enumerations/accesslevels.h"

class UniversityRoom : public Room
{
public:
    UniversityRoom();

private:
    AccessLevel needed_access_level;

};

#endif // UNIVERSITYROOM_H
