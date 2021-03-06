#ifndef ROOMLOCATION_H
#define ROOMLOCATION_H
#include <ostream>

class RoomLocation
{
public:
    enum class Place{
        university,
        campuse
    };

    RoomLocation(Place building = Place::university, short floor = 0, short room_number = 0,short campuse_num = 0);

    void setRoomLocation(Place building = Place::university, short floor = 0, short room_number = 0,short campuse_num = 0);

    friend std::ostream& operator<<(std::ostream& os, const RoomLocation& l);
private:
    Place building;
    short floor;
    short room_number;
    short campuse_number;

};

#endif // ROOMLOCATION_H
