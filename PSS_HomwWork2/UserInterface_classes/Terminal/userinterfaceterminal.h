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
    static inline void printWelcomeText(University& university);

    static inline void printSeparator();
    static inline void getInput(std::string& input);
    static inline void waitENTER();
    static inline bool isNumber(const std::string& num);
    static inline void clear();

    template <class T>
    static int calculateInput(std::string input, std::initializer_list<T> list );
};

#endif // USERINTERFACETERMINAL_H
