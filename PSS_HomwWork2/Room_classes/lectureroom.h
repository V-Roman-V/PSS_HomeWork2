#ifndef LECTUREROOM_H
#define LECTUREROOM_H

#include "universityroom.h"

class LectureRoom : public UniversityRoom
{
public:
    LectureRoom();

private:
    virtual AccessLevel neededAccessLevel() override;
};

#endif // LECTUREROOM_H
