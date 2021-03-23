#ifndef ADMIN_H
#define ADMIN_H

#include "universitypeople.h"

using Position = UniversityPeople::Position;

class Admin : public UniversityPeople
{
public:
    Admin(const People& p = People(), std::string password = "password");

    virtual Position getPosition() const override;

    virtual bool isAdmin() const override;

    void giveAccess(UniversityPeople* people, UniversityRoom* room);
    void giveAccess(UniversityPeople* people, AccessLevel level);

    bool checkPassword(const std::string& pass);
private:
    std::string password;
};

#endif // ADMIN_H
