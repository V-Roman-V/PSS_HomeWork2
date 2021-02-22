#ifndef LABEMPLOYEES_H
#define LABEMPLOYEES_H

#include "universitypeople.h"

class LabEmployees : public UniversityPeople
{
public:
    LabEmployees();
    virtual Position getPosition() override;
};

#endif // LABEMPLOYEES_H
