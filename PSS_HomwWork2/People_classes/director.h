#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "universitypeople.h"

class Director : public UniversityPeople
{
public:
    Director();
    virtual Position getPosition() override;
};

#endif // DIRECTOR_H
