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

    for(auto g: guest)
        delete g;
    guest.clear();

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

void University::addGuest(const People &people)
{
    guest.push_back(new Guest(people));
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
    for(auto g:guest)
        info<<g->getCommonInfo()<<std::endl;
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
    for(auto g:guest)
        info<<g->getFullInfo()<<std::endl;
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

void University::getPeopleByType(UniversityPeople::Position type, std::vector<UniversityPeople *> &people)
{
    switch(type){
        case Position::director:     people.push_back(director); break;
        case Position::admin:        people = std::vector<UniversityPeople*>(admins.begin(),admins.end());break;
        case Position::lab_employee: people = std::vector<UniversityPeople*>(lab_employees.begin(),lab_employees.end());break;
        case Position::professor:    people = std::vector<UniversityPeople*>(professors.begin(),professors.end());break;
        case Position::student:      people = std::vector<UniversityPeople*>(students.begin(),students.end());break;
        case Position::guest:        people = std::vector<UniversityPeople*>(guest.begin(),guest.end());break;
    }
}


Director* University::getDirector()
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

std::vector<Guest *>& University::getGuest()
{
    return guest;
}


void University::getRoomByType(UniversityRoom::RoomType type, std::vector<Room *> &rooms)
{
    switch(type){
        case RoomType::cabinet:          rooms = std::vector<Room*>(cabinet_room.begin(),cabinet_room.end()); [[clang::fallthrough]];
        case RoomType::director_cabinet: rooms.push_back(static_cast<Room*>(director_cabinet));break;
        case RoomType::class_room:       rooms = std::vector<Room*>(class_room.begin(),class_room.end());break;
        case RoomType::conference_room:  rooms = std::vector<Room*>(conference_room.begin(),conference_room.end());break;
        case RoomType::lecture_room:     rooms = std::vector<Room*>(lecture_room.begin(),lecture_room.end());break;
        case RoomType::living_room:      rooms = std::vector<Room*>(living_room.begin(),living_room.end());break;
    }
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

std::vector<RoomType> University::getAllRoomType(){
    std::vector<RoomType> pos;
    pos.push_back(RoomType::cabinet);
    pos.push_back(RoomType::class_room);
    pos.push_back(RoomType::lecture_room);
    pos.push_back(RoomType::conference_room);
    pos.push_back(RoomType::living_room);
    return pos;
}

std::vector<Position> University::getAllPositions()
{
    std::vector<Position> pos;
    pos.push_back(Position::director);
    pos.push_back(Position::admin);
    pos.push_back(Position::lab_employee);
    pos.push_back(Position::professor);
    pos.push_back(Position::student);
    pos.push_back(Position::guest);
    return pos;
}

std::vector<AccessLevel> University::getAllAccessLevels()
{
    std::vector<AccessLevel> type;
    type.push_back(AccessLevel::no_level);
    type.push_back(AccessLevel::blue);
    type.push_back(AccessLevel::green);
    type.push_back(AccessLevel::yellow);
    type.push_back(AccessLevel::red);
    type.push_back(AccessLevel::black);
    return type;
}

std::vector<std::string> University::getAllRoomAccess()
{
    std::string noLev = getAccessLevelName(AccessLevel::no_level);
    std::vector<std::string> acc;
    acc.push_back(UniversityRoom::getRoomTypeName(RoomType::cabinet) + " = " + (emergency?noLev:Cabinet::getNeededLevel()));
    acc.push_back(UniversityRoom::getRoomTypeName(RoomType::class_room) + " = " + (emergency?noLev:ClassRoom::getNeededLevel()));
    acc.push_back(UniversityRoom::getRoomTypeName(RoomType::lecture_room) + " = " + (emergency?noLev:LectureRoom::getNeededLevel()));
    acc.push_back(UniversityRoom::getRoomTypeName(RoomType::conference_room) + " = " + (emergency?noLev:ConferenceRoom::getNeededLevel()));
    return acc;
}

void University::startEmergency()
{
    emergency = true;

    director_cabinet->startEmergency();

    for(auto c: cabinet_room)
        c->startEmergency();

    for(auto c: class_room)
        c->startEmergency();

    for(auto c: conference_room)
        c->startEmergency();

    for(auto c: lecture_room)
        c->startEmergency();

}
void University::stopEmergency()
{
    emergency = false;

    director_cabinet->stopEmergency();

    for(auto c: cabinet_room)
        c->stopEmergency();

    for(auto c: class_room)
        c->stopEmergency();

    for(auto c: conference_room)
        c->stopEmergency();

    for(auto c: lecture_room)
        c->stopEmergency();

}

bool University::isEmergency()
{
    return emergency;
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



