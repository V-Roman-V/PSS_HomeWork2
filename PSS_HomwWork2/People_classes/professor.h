#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "universitypeople.h"
#include "Room_classes/cabinet.h"

using Position = UniversityPeople::Position;

class Cabinet;

class Professor : public UniversityPeople
{
public:
    Professor();
    Professor(const People& p, Cabinet* _cabinet, std::string t_course);

    virtual Position getPosition() const override;

    void setCabinet(Cabinet *value);

    virtual std::string getFullInfo()const override;

private:
    Cabinet* cabinet;
    std::string teaching_course;

    void init();

};

#endif // PROFESSOR_H
