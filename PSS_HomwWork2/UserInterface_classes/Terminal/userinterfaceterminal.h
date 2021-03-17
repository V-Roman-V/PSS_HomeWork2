#ifndef USERINTERFACETERMINAL_H
#define USERINTERFACETERMINAL_H

#include "University_classes/university.h"

#include <iostream>
#include <cstdlib>
#include <iomanip>

#include <vector>

class UserInterfaceTerminal
{
public:
    static void start(University& university);

    static const std::string LINE;

private:
    static inline void printSeparator();
    static inline void getInput(std::string& input);
    static inline void waitENTER();
    static inline bool isNumber(std::string& num);
};

#endif // USERINTERFACETERMINAL_H
