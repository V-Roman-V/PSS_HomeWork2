#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "universitypeople.h"

using Position = UniversityPeople::Position;

class Director : public UniversityPeople
{
public:
    Director();
    virtual Position getPosition() const override;
};

#endif // DIRECTOR_H
