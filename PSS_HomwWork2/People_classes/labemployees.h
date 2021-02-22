#ifndef LABEMPLOYEES_H
#define LABEMPLOYEES_H

#include "universitypeople.h"

using Position = UniversityPeople::Position;

class LabEmployees : public UniversityPeople
{
public:
    LabEmployees();
    virtual Position getPosition() const override;
};

#endif // LABEMPLOYEES_H
