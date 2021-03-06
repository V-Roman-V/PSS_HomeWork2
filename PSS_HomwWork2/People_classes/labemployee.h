#ifndef LABEMPLOYEE_H
#define LABEMPLOYEE_H

#include "universitypeople.h"

using Position = UniversityPeople::Position;

class LabEmployee : public UniversityPeople
{
public:
    LabEmployee(const People& p = People());

    virtual Position getPosition() const override;
};

#endif // LABEMPLOYEE_H
