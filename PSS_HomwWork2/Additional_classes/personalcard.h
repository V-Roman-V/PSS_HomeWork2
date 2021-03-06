#ifndef PERSONALCARD_H
#define PERSONALCARD_H

#include "Enumerations/accesslevels.h"
#include "Additional_classes/roomlocation.h"
#include <vector>

class PersonalCard
{
public:
    PersonalCard();

    void setAccessLevel(const AccessLevel &value);

    const std::vector<RoomLocation>& getMovementHistory() const;

    AccessLevel getAccessLevel() const;

    unsigned int getUniqueCode() const;

private:
    static unsigned int count_card;
    AccessLevel access_level;
    unsigned int unique_code;

    std::vector<RoomLocation> movement_history;
};

#endif // PERSONALCARD_H
