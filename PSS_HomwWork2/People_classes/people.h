#ifndef PEOPLE_H
#define PEOPLE_H
#include <string>
#include "Additional_classes/date.h"
#include "Additional_classes/passport.h"

class People
{
public:
    enum class Gender{unknown, male, female};

    People(const std::string& _name = "",
           const Gender& _gender = Gender::unknown,
           const Date& _date_of_birth = Date(),
           const Passport& _passport = Passport(),
           const std::string& _phone_number = "",
           const std::string& _nationality = ""
          );

    void setPeople(const std::string& _name = "",
                   const Gender& _gender = Gender::unknown,
                   const Date& _date_of_birth = Date(),
                   const Passport& _passport = Passport(),
                   const std::string& _phone_number = "",
                   const std::string& _nationality = ""
                  );

    virtual ~People() = default;


    virtual std::string getInfo();

    std::string getName() const;
    void setName(const std::string &value);

    Date getDateOfBirth() const;
    void setDateOfBirth(const Date &value);

    Passport getPassport() const;
    void setPassport(const Passport &value);

    unsigned short getAge() const;

    Gender getGender() const;
    void setGender(const Gender &value);

    std::string getNationality() const;
    void setNationality(const std::string &value);

    std::string getPhoneNumber() const;
    void setPhoneNumber(const std::string &value);

private:
    std::string name;
    Date date_of_birth;
    Passport passport;
    Gender gender;
    std::string nationality;
    std::string phone_number;
};

#endif // PEOPLE_H
