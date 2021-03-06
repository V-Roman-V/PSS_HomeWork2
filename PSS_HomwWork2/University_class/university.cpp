#include "university.h"
#include <sstream>

University::University(const std::string &name)
    :name(name),director(nullptr)
{

}

University::~University()
{
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
    info<<"Director:"<<std::endl;
    info<<director->getFullInfo(); // getCommonInfo;
    info<<"Admins:"<<std::endl;
    for(auto a:admins)
        info<<a->getFullInfo()<<std::endl;
    info<<"Lab employess:"<<std::endl;
    for(auto le:lab_employees)
        info<<le->getFullInfo()<<std::endl;
    info<<"Professors:"<<std::endl;
    for(auto pr:professors)
        info<<pr->getFullInfo()<<std::endl;
    info<<"Students:"<<std::endl;
    for(auto s:students)
        info<<s->getFullInfo()<<std::endl;
    return info.str();
}



