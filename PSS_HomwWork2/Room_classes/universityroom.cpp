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

std::string UniversityRoom::getRoomTypeName(UniversityRoom::RoomType t)
{
    switch (t) {
        case UniversityRoom::RoomType::cabinet         :return"cabinet";
        case UniversityRoom::RoomType::director_cabinet:return"director cabinet";
        case UniversityRoom::RoomType::class_room      :return"class room";
        case UniversityRoom::RoomType::conference_room :return"conference room";
        case UniversityRoom::RoomType::lecture_room    :return"lecture room";
    }
    return "";
}

AccessLevel UniversityRoom::neededAccessLevel() const
{
    return AccessLevel::no_level;
}
