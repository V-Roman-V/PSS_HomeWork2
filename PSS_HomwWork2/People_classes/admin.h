#ifndef ADMIN_H
#define ADMIN_H

#include "universitypeople.h"

using Position = UniversityPeople::Position;

class Admin : public UniversityPeople
{
public:
    Admin();

    virtual Position getPosition() const override;

    void giveAcces();
};

#endif // ADMIN_H
