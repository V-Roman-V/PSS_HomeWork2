#ifndef CABINET_H
#define CABINET_H

#include "universityroom.h"
#include "People_classes/people.h"

class Cabinet : public UniversityRoom
{
public:
    Cabinet();

private:
    People* workers;
    virtual AccessLevel neededAccessLevel() override;
};

#endif // CABINET_H
