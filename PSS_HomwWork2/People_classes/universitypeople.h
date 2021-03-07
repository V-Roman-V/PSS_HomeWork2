#ifndef UNIVERSITYPEOPLE_H
#define UNIVERSITYPEOPLE_H

#include "people.h"
#include "Additional_classes/personalcard.h"
#include <vector>
#include "Room_classes/universityroom.h"
#include "Enumerations/accesslevels.h"

class UniversityRoom;

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

    virtual std::string getCommonInfo() const override;
    virtual std::string getFullInfo() const override;

    bool tryToEnter(UniversityRoom* room);

    void changeAccesLevel(AccessLevel level);

    void addSpecialAccessRoom(UniversityRoom* room);

    int getPersonalId() const;
protected:
    std::vector<UniversityRoom*> special_access;
    PersonalCard card;
    std::string getPozitionName(Position p)const;

};

#endif // UNIVERSITYPEOPLE_H
