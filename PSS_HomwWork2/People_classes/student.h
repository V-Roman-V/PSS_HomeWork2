#ifndef STUDENT_H
#define STUDENT_H

#include "universitypeople.h"
#include "Room_classes/livingroom.h"

using Position = UniversityPeople::Position;

class Student : public UniversityPeople
{
public:
    Student();
    virtual Position getPosition() const override;

private:
    LivingRoom* room;
    unsigned short course_number;
};

#endif // STUDENT_H
