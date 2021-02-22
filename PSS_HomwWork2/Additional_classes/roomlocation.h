#ifndef ROOMLOCATION_H
#define ROOMLOCATION_H


class RoomLocation
{
public:
    enum class Place{
        university,
        campuse
    };

    RoomLocation(Place building = Place::university, short floor = 0, short room_number = 0);

    void setRoomLocation(Place building = Place::university, short floor = 0, short room_number = 0);

    Place getBuilding() const;

    short getFloor() const;

    short getRoom_number() const;

private:
    Place building;
    short floor;
    short room_number;

};

#endif // ROOMLOCATION_H
