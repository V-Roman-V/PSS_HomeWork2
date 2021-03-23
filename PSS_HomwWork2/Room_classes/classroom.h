#ifndef CLASSROOM_H
#define CLASSROOM_H

#include "universityroom.h"

using RoomType = UniversityRoom::RoomType;

class ClassRoom : public UniversityRoom
{
public:
    ClassRoom(const RoomLocation& l = RoomLocation());

    virtual RoomType getRoomType() const override;
    static std::string getNeededLevel();
};


#endif // CLASSROOM_H
