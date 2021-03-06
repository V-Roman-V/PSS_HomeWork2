#ifndef CONFERENCEROOM_H
#define CONFERENCEROOM_H

#include "universityroom.h"

using RoomType = UniversityRoom::RoomType;

class ConferenceRoom : public UniversityRoom
{
public:
    ConferenceRoom(const RoomLocation& l = RoomLocation());

    virtual RoomType getRoomType() const override;
private:
    virtual AccessLevel neededAccessLevel() override;
};

#endif // CONFERENCEROOM_H
