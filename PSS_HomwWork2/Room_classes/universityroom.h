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

    AccessLevel neededAccessLevel() const;

    static std::string getNeededLevel();

    static std::string getRoomTypeName(const RoomType& t);

    void startEmergency();
    void stopEmergency();
protected:
    AccessLevel myAccessLevel = AccessLevel::no_level;
    bool emergency = false;

};

#endif // UNIVERSITYROOM_H
