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
        lecture_room,
        living_room //To generalize interface
    };

    UniversityRoom(const RoomLocation& l = RoomLocation(),unsigned short max_people = 25);

    virtual std::string getInfo() override;

    virtual RoomType getRoomType() const = 0;

    virtual AccessLevel neededAccessLevel() const = 0;

    static std::string getNeededLevel();

    static std::string getRoomTypeName(const RoomType& t);


};

#endif // UNIVERSITYROOM_H
