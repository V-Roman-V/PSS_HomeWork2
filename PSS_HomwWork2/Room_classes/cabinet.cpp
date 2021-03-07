#include "cabinet.h"
#include <sstream>

Cabinet::Cabinet(const RoomLocation &l, unsigned short max_people)
    :UniversityRoom(l)
{
    max_number_of_people = max_people;
}

UniversityRoom::RoomType Cabinet::getRoomType() const
{
    return RoomType::cabinet;
}

std::string Cabinet::getInfo()
{
    std::stringstream info;
    info<<Room::getInfo();
    info<<"\tWorkers("<<getCountWorkers()<<"): "<<std::endl;
    for(auto worker:workers)
        info<<"\t\t"<<worker->getName()<<std::endl;
    return info.str();
}

void Cabinet::addWorker(Professor *p)
{
    workers.push_back(p);
    p->setCabinet(this);
}
void Cabinet::addWorker(LabEmployee *p)
{
    workers.push_back(p);
    p->setCabinet(this);
}

int Cabinet::getCountWorkers()
{
    return workers.size();
}

AccessLevel Cabinet::neededAccessLevel()const
{
    return AccessLevel::red;
}
