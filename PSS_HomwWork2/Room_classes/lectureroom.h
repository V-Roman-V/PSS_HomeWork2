#ifndef LECTUREROOM_H
#define LECTUREROOM_H

#include "universityroom.h"

using RoomType = UniversityRoom::RoomType;

class LectureRoom : public UniversityRoom
{
public:
    LectureRoom(const RoomLocation& l = RoomLocation(), unsigned short max_people = 5);

    virtual RoomType getRoomType() const override;
    virtual AccessLevel neededAccessLevel() const override;
};

#endif // LECTUREROOM_H
