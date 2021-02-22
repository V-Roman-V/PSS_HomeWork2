#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "universitypeople.h"
#include "Room_classes/cabinet.h"

using Position = UniversityPeople::Position;

class Professor : public UniversityPeople
{
public:
    Professor();
    virtual Position getPosition() const override;

private:
    std::string teaching_course;
    Cabinet* cabinet;

};

#endif // PROFESSOR_H
