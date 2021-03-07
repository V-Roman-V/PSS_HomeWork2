#ifndef LABEMPLOYEE_H
#define LABEMPLOYEE_H

#include "universitypeople.h"
#include "Room_classes/cabinet.h"

using Position = UniversityPeople::Position;

class Cabinet;

class LabEmployee : public UniversityPeople
{
public:
    LabEmployee(const People& p = People());

    virtual Position getPosition() const override;

    void setCabinet(Cabinet *value);

    virtual std::string getFullInfo() override;

private:
    Cabinet* cabinet;
};

#endif // LABEMPLOYEE_H
