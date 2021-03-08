#ifndef CABINET_H
#define CABINET_H

#include "universityroom.h"
#include "People_classes/universitypeople.h"
#include "People_classes/professor.h"
#include "People_classes/labemployee.h"
#include "People_classes/director.h"

using RoomType = UniversityRoom::RoomType;

class Professor;
class LabEmployee;
class Director;

class Cabinet : public UniversityRoom
{
public:
    Cabinet(const RoomLocation& l = RoomLocation(), unsigned short max_people = 5);

    virtual RoomType getRoomType() const override;

    virtual std::string getInfo() override;

    virtual void addWorker(Director*){}
    void addWorker(LabEmployee* p);
    void addWorker(Professor* p);
    int getCountWorkers();

    static std::string getNeededLevel();

    virtual AccessLevel neededAccessLevel()const override;
protected:
    std::vector<UniversityPeople*> workers;
};

#endif // CABINET_H
