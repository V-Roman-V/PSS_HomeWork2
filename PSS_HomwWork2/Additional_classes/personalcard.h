#ifndef PERSONALCARD_H
#define PERSONALCARD_H

#include "Enumerations/accesslevels.h"
#include "Room_classes/universityroom.h"
#include <vector>

class UniversityRoom;

class PersonalCard
{
public:
    PersonalCard();

    void setAccessLevel(const AccessLevel &value);

    const std::vector<std::string>& getMovementHistory() const;

    void addMovemontHistory(UniversityRoom* room);

    AccessLevel getAccessLevel() const;

    unsigned int getUniqueCode() const;

private:
    static unsigned int count_card;
    AccessLevel access_level;
    unsigned int unique_code;

    std::vector<std::string> movement_history;
};

#endif // PERSONALCARD_H
