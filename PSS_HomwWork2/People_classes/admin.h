#ifndef ADMIN_H
#define ADMIN_H

#include "universitypeople.h"

using Position = UniversityPeople::Position;

class Admin : public UniversityPeople
{
public:
    Admin(const People& p = People());

    virtual Position getPosition() const override;

    void giveAcces(UniversityPeople* people, Room* room);
};

#endif // ADMIN_H
