#ifndef LOGGER_H
#define LOGGER_H
#include <fstream>


class Logger
{
public:
    Logger();
    ~Logger();
    void addActions(const std::string& act);
    void updatePeople(const std::string& people);
    void updateRoom(const std::string& room);

private:
    std::ofstream logPeople;
    std::ofstream logRoom;
    std::ofstream logActions;
    unsigned int actionNum = 0;
};

#endif // LOGGER_H
