#ifndef ADMINS_H
#define ADMINS_H

#include "universitypeople.h"

using Position = UniversityPeople::Position;

class Admins : public UniversityPeople
{
public:
    Admins();

    virtual Position getPosition() const override;

    void giveAcces();
};

#endif // ADMINS_H
