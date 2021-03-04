#include "university.h"


University::University(const std::string &name)
    :name(name)
{

}

UniversityPeople &University::newEmployess(const UniversityPeople &employee)
{
    //    employees.push_back();
}

Student &University::newStudent(const Student &student)
{
    students.push_back( new Student(student));
}

void University::setDirector(Director *value)
{
    director = value;
}
