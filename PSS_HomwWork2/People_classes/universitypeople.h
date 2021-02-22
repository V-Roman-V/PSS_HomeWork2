#ifndef UNIVERSITYPEOPLE_H
#define UNIVERSITYPEOPLE_H

#include "people.h"
#include "Additional_classes/personalcard.h"
#include <vector>
#include "Room_classes/universityroom.h"

class UniversityPeople : public People
{
public:
    enum class Position{
        student,
        professor,
        lab_employee,
        director,
        admin
    };

    UniversityPeople();
    virtual ~UniversityPeople() override = default;

    virtual Position getPosition() const = 0;

protected:
    PersonalCard* card;
    std::vector<UniversityRoom*> special_access;

};

#endif // UNIVERSITYPEOPLE_H
