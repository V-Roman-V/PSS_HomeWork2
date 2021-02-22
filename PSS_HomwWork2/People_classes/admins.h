#ifndef ADMINS_H
#define ADMINS_H

#include "universitypeople.h"

class Admins : public UniversityPeople
{
public:
    Admins();

    virtual Position getPosition() override;

    void giveAcces();
};

#endif // ADMINS_H
