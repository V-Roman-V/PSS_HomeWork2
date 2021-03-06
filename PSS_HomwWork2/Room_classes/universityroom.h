#ifndef UNIVERSITYROOM_H
#define UNIVERSITYROOM_H

#include "room.h"
#include "Enumerations/accesslevels.h"

class UniversityRoom : public Room
{
public:
    enum class RoomType{
        cabinet,
        director_cabinet,
        class_room,
        conference_room,
        lecture_room
    };

    UniversityRoom(const RoomLocation& l = RoomLocation(),unsigned short max_people = 25);

    virtual std::string getInfo() override;

    virtual RoomType getRoomType() const = 0;
private:
    virtual AccessLevel neededAccessLevel() = 0;
protected:
    std::string getRoomTypeName(RoomType t);


};

#endif // UNIVERSITYROOM_H
