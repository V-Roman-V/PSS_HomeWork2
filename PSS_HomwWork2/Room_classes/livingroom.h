#ifndef LIVINGROOM_H
#define LIVINGROOM_H

#include "room.h"
#include <vector>
#include "People_classes/people.h"
#include "People_classes/student.h"

class Student;

class LivingRoom : public Room
{
public:
    LivingRoom(const RoomLocation& l = RoomLocation(),unsigned short max_people = 2);


    void addResidents(Student * p);
    int getCountResidents();

    virtual std::string getInfo() override;

private:
    std::vector<Student*> residents;
    unsigned short current_number_of_people;
};

#endif // LIVINGROOM_H
