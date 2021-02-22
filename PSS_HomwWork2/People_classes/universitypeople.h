#ifndef UNIVERSITYPEOPLE_H
#define UNIVERSITYPEOPLE_H

#include "people.h"
#include "Additional_classes/personalcard.h"
#include "Enumerations/position.h"

class UniversityPeople : public People
{
public:
    UniversityPeople();
    virtual ~UniversityPeople() = default;

    virtual Position getPosition() = 0;

protected:
    PersonalCard card;

};

#endif // UNIVERSITYPEOPLE_H
