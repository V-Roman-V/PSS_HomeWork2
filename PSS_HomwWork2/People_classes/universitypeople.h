#ifndef UNIVERSITYPEOPLE_H
#define UNIVERSITYPEOPLE_H

#include "people.h"
#include "Additional_classes/personalcard.h"
#include <vector>
#include "Room_classes/universityroom.h"
#include "Enumerations/accesslevels.h"
//#include "People_classes/admin.h"

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
    static std::string getPozitionName(const Position& p);

    UniversityPeople(const People& p = People());

    virtual ~UniversityPeople() override = default;

    virtual Position getPosition() const = 0;

    virtual std::string getCommonInfo() const override;
    virtual std::string getFullInfo() const override;

    virtual bool isAdmin() const;

    bool tryToEnter(UniversityRoom* room);

    void addSpecialAccessRoom(UniversityRoom* room);

    int getPersonalId() const;

    std::string getMovementHistory() const;

    AccessLevel getAccessLevel() const;

    void changeAccessLevel(AccessLevel level);

protected:
    std::vector<UniversityRoom*> special_access;
    PersonalCard card;

};

#endif // UNIVERSITYPEOPLE_H
