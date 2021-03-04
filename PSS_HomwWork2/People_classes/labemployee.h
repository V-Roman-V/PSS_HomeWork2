#ifndef LABEMPLOYEE_H
#define LABEMPLOYEE_H

#include "universitypeople.h"

using Position = UniversityPeople::Position;

class LabEmployee : public UniversityPeople
{
public:
    LabEmployee();
    virtual Position getPosition() const override;
};

#endif // LABEMPLOYEE_H
