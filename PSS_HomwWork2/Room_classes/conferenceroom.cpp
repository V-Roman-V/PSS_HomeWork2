#include "conferenceroom.h"

ConferenceRoom::ConferenceRoom()
{

}

AccessLevel ConferenceRoom::neededAccessLevel()
{
    return AccessLevel::red;
}
