#ifndef USERINTERFACETERMINAL_H
#define USERINTERFACETERMINAL_H

#include "University_classes/university.h"
#include "Logger_classes/logger.h"

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
    static Logger logger;
    static inline void printWelcomeText(University& university);

    static inline void printSeparator();
    static inline void getInput(std::string& input);
    static inline void waitENTER();
    static inline bool isNumber(const std::string& num);
    static inline void clear();

    static std::string getListOptions(std::vector<std::string> list);

    static int calculateInput(std::string input, std::vector<std::string> list );
};

#endif // USERINTERFACETERMINAL_H
