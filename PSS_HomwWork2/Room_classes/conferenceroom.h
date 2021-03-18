#ifndef CONFERENCEROOM_H
#define CONFERENCEROOM_H

#include "universityroom.h"

using RoomType = UniversityRoom::RoomType;

class ConferenceRoom : public UniversityRoom
{
public:
    ConferenceRoom(const RoomLocation& l = RoomLocation(), unsigned short max_people = 5);

    virtual RoomType getRoomType() const override;
    virtual AccessLevel neededAccessLevel()const  override;
    static std::string getNeededLevel();
};

#endif // CONFERENCEROOM_H
