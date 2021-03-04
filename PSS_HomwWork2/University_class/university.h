#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <vector>
#include "Room_classes/room.h"
#include "Room_classes/livingroom.h"
#include "Room_classes/universityroom.h"
#include "People_classes/admin.h"
#include "People_classes/director.h"
#include "People_classes/labemployee.h"
#include "People_classes/professor.h"
#include "People_classes/student.h"

class University
{
public:
    University(const std::string& name = "University");

    UniversityPeople& newEmployess(const UniversityPeople& people);

    Student& newStudent(const Student& student);

    void setDirector(const People& people );

private:
    std::string name;
    std::vector<LivingRoom*> campuse;
    std::vector<UniversityRoom*> university;

    Director* director;
    std::vector<Admin*> admins;
    std::vector<LabEmployee*> lab_employees;
    std::vector<Professor*> professors;
    std::vector<Student*> students;

};

#endif // UNIVERSITY_H
