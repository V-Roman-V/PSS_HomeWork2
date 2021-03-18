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
    for(auto clr: class_room)
        delete clr;
    class_room.clear();

    for(auto cor: conference_room)
        delete cor;
    conference_room.clear();

    for(auto lr: lecture_room)
        delete lr;
    lecture_room.clear();

    for(auto c: cabinet_room)
        delete c;
    cabinet_room.clear();

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

void University::addAdmin(const People &people, std::string pass)
{
    admins.push_back(new Admin(people,pass));
}

void University::setDirector(const People &people)
{
    if(!director)
        delete director;
    director = new Director(people);
}

std::string University::getCommonListPeoples()
{
    std::stringstream info;
    if(director){
        info<<"Director:"<<std::endl;
        info<<director->getCommonInfo();
    }
    info<<"Admins("<<admins.size()<<"):"<<std::endl;
    for(auto a:admins)
        info<<a->getCommonInfo()<<std::endl;
    info<<"Lab employess("<<lab_employees.size()<<"):"<<std::endl;
    for(auto le:lab_employees)
        info<<le->getCommonInfo()<<std::endl;
    info<<"Professors("<<professors.size()<<"):"<<std::endl;
    for(auto pr:professors)
        info<<pr->getCommonInfo()<<std::endl;
    info<<"Students("<<students.size()<<"):"<<std::endl;
    for(auto s:students)
        info<<s->getCommonInfo()<<std::endl;
    return info.str();
}

std::string University::getFullListPeoples()
{
    std::stringstream info;
    if(director){
        info<<"Director:"<<std::endl;
        info<<director->getFullInfo();
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


void University::addCabinet(const RoomLocation &location, unsigned short max_people)
{
    cabinet_room.push_back(new Cabinet(location, max_people));
}

void University::addClassRoom(const RoomLocation &location)
{
    class_room.push_back(new ClassRoom(location));
}

void University::addConferenceRoom(const RoomLocation &location, unsigned short max_people)
{
    conference_room.push_back(new ConferenceRoom(location, max_people));
}

void University::addLectureRoom(const RoomLocation &location, unsigned short max_people)
{
    lecture_room.push_back(new LectureRoom(location, max_people));
}

void University::addLivingRoom(const RoomLocation &location, unsigned short max_people)
{
    living_room.push_back(new LivingRoom(location, max_people));
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
    info<<"Class rooms ("<<class_room.size()<<"):"<<std::endl;
    for(auto c:class_room)
        info<<c->getInfo()<<std::endl;
    info<<"Conference rooms ("<<conference_room.size()<<"):"<<std::endl;
    for(auto c:conference_room)
        info<<c->getInfo()<<std::endl;
    info<<"Lecture rooms ("<<lecture_room.size()<<"):"<<std::endl;
    for(auto c:lecture_room)
        info<<c->getInfo()<<std::endl;
    info<<"Cabinets ("<<cabinet_room.size()<<"):"<<std::endl;
    for(auto c:cabinet_room)
        info<<c->getInfo()<<std::endl;
    info<<"Living rooms("<<living_room.size()<<"):"<<std::endl;
    for(auto l:living_room)
        info<<l->getInfo()<<std::endl;
    return info.str();
}

Director *University::getDirector()
{
    return director;
}

std::vector<Admin *>& University::getAdmins()
{
    return admins;
}

std::vector<LabEmployee *>& University::getLabEmployees()
{
    return lab_employees;
}

std::vector<Professor *>& University::getProfessors()
{
    return professors;
}

std::vector<Student *>& University::getStudents()
{
    return students;
}

DirectorCabinet *University::getDirectorCabinet()
{
    return director_cabinet;
}

std::vector<Cabinet *>& University::getCabinetRoom()
{
    return cabinet_room;
}

std::vector<LivingRoom *>& University::getLivingRoom()
{
    return living_room;
}

std::string University::getName() const
{
    return name;
}

std::vector<ClassRoom *>& University::getClassRoom()
{
    return class_room;
}

std::vector<ConferenceRoom *>& University::getConferenceRoom()
{
    return conference_room;
}

std::vector<LectureRoom *>& University::getLectureRoom()
{
    return lecture_room;
}



