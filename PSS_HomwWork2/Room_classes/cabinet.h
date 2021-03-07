#ifndef CABINET_H
#define CABINET_H

#include "universityroom.h"
#include "People_classes/universitypeople.h"
#include "People_classes/professor.h"
#include "People_classes/labemployee.h"

using RoomType = UniversityRoom::RoomType;

class Professor;
class LabEmployee;

class Cabinet : public UniversityRoom
{
public:
    Cabinet(const RoomLocation& l = RoomLocation(), unsigned short max_people = 5);

    virtual RoomType getRoomType() const override;

    virtual std::string getInfo() override;

    void addWorker(LabEmployee* p);
    void addWorker(Professor* p);
    int getCountWorkers();
private:
    std::vector<UniversityPeople*> workers;
    virtual AccessLevel neededAccessLevel() override;
};

#endif // CABINET_H
