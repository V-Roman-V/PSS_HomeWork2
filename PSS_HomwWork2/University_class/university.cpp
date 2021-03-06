#include "university.h"
#include <sstream>

University::University(const std::string &name)
    :name(name),director(nullptr),director_cabinet(nullptr)
{

}

University::~University()
{
    // delete peoples
    for(auto a: admins)
        delete a;
    admins.clear();

    for(auto le: lab_employees)
        delete le;
    lab_employees.clear();

    for(auto pr: professors)
        delete pr;
    professors.clear();

    for(auto s: students)
        delete s;
    students.clear();

    delete director;
    director = nullptr;

    // delete rooms
    for(auto r: university_room)
        delete r;
    university_room.clear();

    for(auto l: living_room)
        delete l;
    living_room.clear();

    delete director_cabinet;
    director_cabinet = nullptr;
}

void University::addStudent(const People &people, LivingRoom* lroom, unsigned short course)
{
    students.push_back(new Student(people, lroom, course));
}

void University::addEmployess(const People &people)
{
    lab_employees.push_back(new LabEmployee(people));
}

void University::addProfessor(const People &people, Cabinet* cabinet, const std::string& course)
{
    professors.push_back(new Professor(people, cabinet, course));
}

void University::addAdmin(const People &people)
{
    admins.push_back(new Admin(people));
}

void University::setDirector(const People &people)
{
    if(!director)
        delete director;
    director = new Director(people);
}

std::string University::getListPeoples()
{
    std::stringstream info;
    if(director){
        info<<"Director:"<<std::endl;
        info<<director->getFullInfo(); // getCommonInfo;
    }
    info<<"Admins("<<admins.size()<<"):"<<std::endl;
    for(auto a:admins)
        info<<a->getFullInfo()<<std::endl;
    info<<"Lab employess("<<lab_employees.size()<<"):"<<std::endl;
    for(auto le:lab_employees)
        info<<le->getFullInfo()<<std::endl;
    info<<"Professors("<<professors.size()<<"):"<<std::endl;
    for(auto pr:professors)
        info<<pr->getFullInfo()<<std::endl;
    info<<"Students("<<students.size()<<"):"<<std::endl;
    for(auto s:students)
        info<<s->getFullInfo()<<std::endl;
    return info.str();
}


void University::addCabinet(const RoomLocation &location)
{
    university_room.push_back(new Cabinet(location));
}

void University::addClassRoom(const RoomLocation &location)
{
    university_room.push_back(new ClassRoom(location));
}

void University::addConferenceRoom(const RoomLocation &location)
{
    university_room.push_back(new ConferenceRoom(location));
}

void University::addLectureRoom(const RoomLocation &location)
{
    university_room.push_back(new LectureRoom(location));
}

void University::addLivingRoom(const RoomLocation &location)
{
    living_room.push_back(new LivingRoom(location));
}

void University::setDirectorCabinet(const RoomLocation& location)
{
    if(!director_cabinet)
        delete director_cabinet;
    director_cabinet = new DirectorCabinet(location);
}

std::string University::getListRooms()
{
    std::stringstream info;
    if(director_cabinet){
        info<<"Director cabinet:"<<std::endl;
        info<<director_cabinet->getInfo()<<std::endl;
    }
    info<<"University rooms("<<university_room.size()<<"):"<<std::endl;
    for(auto u:university_room)
        info<<u->getInfo()<<std::endl;
    info<<"Living rooms("<<living_room.size()<<"):"<<std::endl;
    for(auto l:living_room)
        info<<l->getInfo()<<std::endl;
    return info.str();
}



