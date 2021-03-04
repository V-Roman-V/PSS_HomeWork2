#ifndef CLASSROOM_H
#define CLASSROOM_H

#include "universityroom.h"

class ClassRoom : public UniversityRoom
{
public:
    ClassRoom();

private:
    virtual AccessLevel neededAccessLevel() override;
};


#endif // CLASSROOM_H
