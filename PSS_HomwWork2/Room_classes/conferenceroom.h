#ifndef CONFERENCEROOM_H
#define CONFERENCEROOM_H

#include "universityroom.h"

class ConferenceRoom : public UniversityRoom
{
public:
    ConferenceRoom();

private:
    virtual AccessLevel neededAccessLevel() override;
};

#endif // CONFERENCEROOM_H
