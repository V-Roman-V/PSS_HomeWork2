#ifndef LECTUREROOM_H
#define LECTUREROOM_H

#include "universityroom.h"

using RoomType = UniversityRoom::RoomType;

class LectureRoom : public UniversityRoom
{
public:
    LectureRoom(const RoomLocation& l = RoomLocation());

    virtual RoomType getRoomType() const override;
private:
    virtual AccessLevel neededAccessLevel() override;
};

#endif // LECTUREROOM_H
