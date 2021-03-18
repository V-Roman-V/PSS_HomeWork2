#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "universitypeople.h"
#include "Room_classes/cabinet.h"

using Position = UniversityPeople::Position;

class Director : public UniversityPeople
{
public:
    Director(const People& p = People());

    virtual Position getPosition() const override;

    void setCabinet(Cabinet *value);

    virtual std::string getFullInfo()const override;

private:

    Cabinet* cabinet;
};

#endif // DIRECTOR_H
