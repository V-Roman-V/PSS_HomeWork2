#ifndef ACCESSLEVELS_H
#define ACCESSLEVELS_H
enum class AccessLevel {
    no_level,// default
    green,   // students
    yellow,  // lab_Employess
    red,     // professors and admins
    black    // only for director
};

#endif // ACCESSLEVELS_H
