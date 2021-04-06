#include "logger.h"

using namespace std;
Logger::Logger()
{
    logActions.open("log_actions.txt");
}

Logger::~Logger()
{
    if(logActions.is_open())
        logActions.close();
    if(logPeople.is_open())
        logPeople.close();
    if(logRoom.is_open())
        logRoom.close();
}

void Logger::addActions(const std::string &act)
{
    logActions<<actionNum++<<") "<<act<<std::endl;
}

void Logger::updatePeople(const string &people)
{
    logPeople.open( "log_people.txt", std::ios::out );
    logPeople<<people;
    logPeople.close();
}

void Logger::updateRoom(const string &room)
{
    logRoom.open( "log_rooms.txt", std::ios::out );
    logRoom<<room;
    logRoom.close();
}
