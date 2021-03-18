#include "livingroom.h"
#include <sstream>

LivingRoom::LivingRoom(const RoomLocation &l, unsigned short max_people)
    :Room(l)
{
    max_number_of_people = max_people;
}

void LivingRoom::addResidents(Student *p)
{
    residents.push_back(p);
    p->setRoom(this);
}

int LivingRoom::getCountResidents()
{
    return residents.size();
}


std::string LivingRoom::getInfo()
{
    std::stringstream info;
    info<<Room::getInfo();
    info<<"\tWorkers("<<getCountResidents()<<"): "<<std::endl;
    for(auto resident:residents)
        info<<"\t\t"<<resident->getName()<<std::endl;
    return info.str();
}
