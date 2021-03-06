#ifndef DIRECTORCABINET_H
#define DIRECTORCABINET_H

#include "cabinet.h"

using RoomType = UniversityRoom::RoomType;

class DirectorCabinet : public Cabinet
{
public:
    DirectorCabinet(const RoomLocation& l = RoomLocation());

    virtual RoomType getRoomType() const override;
private:
    virtual AccessLevel neededAccessLevel() override;
};

#endif // DIRECTORCABINET_H
