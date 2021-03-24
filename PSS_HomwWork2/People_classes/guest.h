#ifndef GUEST_H
#define GUEST_H

#include "universitypeople.h"

using Position = UniversityPeople::Position;

class Guest : public UniversityPeople
{
public:
    Guest(const People& p = People());

    virtual Position getPosition() const override;

private:
    void init();
};

#endif // GUEST_H
