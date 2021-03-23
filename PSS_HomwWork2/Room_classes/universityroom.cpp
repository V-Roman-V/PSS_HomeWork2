#include "universityroom.h"
#include <sstream>

UniversityRoom::UniversityRoom(const RoomLocation &l, unsigned short max_people)
    :Room(l)
{
    max_number_of_people = max_people;
}

std::string UniversityRoom::getInfo()
{
    std::stringstream info;
    info<<"\tRoom type: "<<getRoomTypeName(getRoomType())<<std::endl;
    info<<"\tNeeded acces level: "<<getAccessLevelName(neededAccessLevel())<<std::endl;
    info<<Room::getInfo();
    return info.str();
}

std::string UniversityRoom::getNeededLevel()
{
    return getAccessLevelName(AccessLevel::no_level);
}

std::string UniversityRoom::getRoomTypeName(const UniversityRoom::RoomType& t)
{
    switch (t) {
        case UniversityRoom::RoomType::cabinet         :return"cabinet";
        case UniversityRoom::RoomType::director_cabinet:return"director_cabinet";
        case UniversityRoom::RoomType::class_room      :return"class_room";
        case UniversityRoom::RoomType::conference_room :return"conference_room";
        case UniversityRoom::RoomType::lecture_room    :return"lecture_room";
        case UniversityRoom::RoomType::living_room     :return"living_room";
    }
    return "";
}

void UniversityRoom::startEmergency()
{
    emergency = true;
}

void UniversityRoom::stopEmergency()
{
    emergency = false;
}

AccessLevel UniversityRoom::neededAccessLevel() const
{
    return emergency?AccessLevel::no_level:myAccessLevel;
}
