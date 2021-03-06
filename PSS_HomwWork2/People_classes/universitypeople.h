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

    UniversityPeople(const People& p = People());

    virtual ~UniversityPeople() override = default;

    virtual Position getPosition() const = 0;

    virtual std::string getCommonInfo() override;
    virtual std::string getFullInfo() override;

    bool tryToEnter(const Room* room);

protected:
    PersonalCard card;

};

#endif // UNIVERSITYPEOPLE_H
