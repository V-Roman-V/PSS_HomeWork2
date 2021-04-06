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

    static inline void printSeparator(){std::cout<<LINE<<std::endl;}
    static inline void getInput(std::string& input){std::cout<<'>';std::cin>>input;}
    static inline void waitENTER();
    static inline bool isNumber(const std::string& num){return (num.find_first_not_of( "0123456789" ) == std::string::npos);}
    static inline void clear(){system("cls");}

    static inline std::string StrToStr(const std::string& str){return str;}


    static std::string getListOptions(const std::vector<std::string>& list){return getListOptions(list,StrToStr);}
    static std::string getListOptions(const std::vector<Position>& list)   {return getListOptions(list,UniversityPeople::getPozitionName);}
    static std::string getListOptions(const std::vector<AccessLevel>& list){return getListOptions(list,getAccessLevelName);}
    static std::string getListOptions(const std::vector<RoomType>& list)   {return getListOptions(list,UniversityRoom::getRoomTypeName);}

    static inline int calculateInput(const std::string& input, const std::initializer_list<std::string>& list){return calculateInput(input, std::vector<std::string>(list), StrToStr);}
    static inline int calculateInput(const std::string& input, const std::vector<std::string>& list)          {return calculateInput(input, list, StrToStr);}
    static inline int calculateInput(const std::string& input, const std::vector<Position>& list)             {return calculateInput(input, list, UniversityPeople::getPozitionName);}
    static inline int calculateInput(const std::string& input, const std::vector<AccessLevel>& list)          {return calculateInput(input, list, getAccessLevelName);}
    static inline int calculateInput(const std::string& input, const std::vector<RoomType>& list)             {return calculateInput(input, list, UniversityRoom::getRoomTypeName);}

    template<class T>
    static std::string getListOptions(const std::vector<T>& list, std::string (*f)(const T&));

    template<class T>
    static int calculateInput(const std::string& input, const std::vector<T>& list, std::string (*f)(const T&));

};

#endif // USERINTERFACETERMINAL_H
