#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "universitypeople.h"
#include "Room_classes/cabinet.h"

class Professor : public UniversityPeople
{
public:
    Professor();
    virtual Position getPosition() override;

private:
    std::string teaching_course;
    Cabinet* cabinet;

};

#endif // PROFESSOR_H
