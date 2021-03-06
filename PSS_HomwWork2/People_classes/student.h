#ifndef STUDENT_H
#define STUDENT_H

#include "universitypeople.h"
#include "Room_classes/livingroom.h"

using Position = UniversityPeople::Position;

class Student : public UniversityPeople
{
public:
    Student();
    Student(const People& p, LivingRoom* lroom, unsigned short c_number = 1);

    virtual Position getPosition() const override;

private:
    LivingRoom* room;
    unsigned short course_number;
    void init();
};

#endif // STUDENT_H
