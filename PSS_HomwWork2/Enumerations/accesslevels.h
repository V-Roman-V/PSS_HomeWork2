#ifndef ACCESSLEVELS_H
#define ACCESSLEVELS_H

#include <string>

enum class AccessLevel {
    no_level,// default
    blue,    // guest
    green,   // students
    yellow,  // lab_Employess
    red,     // professors and admins
    black    // only for director
};
std::string getAccessLevelName(AccessLevel l);

#endif // ACCESSLEVELS_H
