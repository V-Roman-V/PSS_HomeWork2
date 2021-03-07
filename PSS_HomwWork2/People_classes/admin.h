#ifndef ADMIN_H
#define ADMIN_H

#include "universitypeople.h"

using Position = UniversityPeople::Position;

class Admin : public UniversityPeople
{
public:
    Admin(const People& p = People(), std::string password = "password");

    virtual Position getPosition() const override;

    void giveAcces(UniversityPeople* people, UniversityRoom* room);
    void giveAcces(UniversityPeople* people, AccessLevel level);

    bool checkPassword(const std::string& pass);
private:
    std::string password;
};

#endif // ADMIN_H
