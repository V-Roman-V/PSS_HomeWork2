#ifndef STUDENT_H
#define STUDENT_H

#include "universitypeople.h"
#include "Room_classes/livingroom.h"

class Student : public UniversityPeople
{
public:
    Student();
    virtual Position getPosition() override;

private:
    LivingRoom* room;
    unsigned short course_number;
};

#endif // STUDENT_H
