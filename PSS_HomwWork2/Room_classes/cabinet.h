#ifndef CABINET_H
#define CABINET_H

#include "universityroom.h"
#include "People_classes/people.h"

using RoomType = UniversityRoom::RoomType;

class Cabinet : public UniversityRoom
{
public:
    Cabinet(const RoomLocation& l = RoomLocation());

    virtual RoomType getRoomType() const override;

private:
    People* worker;
    virtual AccessLevel neededAccessLevel() override;
};

#endif // CABINET_H
