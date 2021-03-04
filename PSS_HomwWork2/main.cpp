#include <iostream>
#include<vector>
#include "University_class/university.h"
#include "Additional_classes/peoplegenerator.h"

using namespace std;
int main()
{
    University Innopolis("Innopolis University");
    vector<People> peoples;
    peoples.push_back(People("Donald",
                             "Park",
                             People::Gender::male,
                             Date(06, 03, 1989),
                             Passport(4767, 235646),
                             "89534210987",
                             "American"
                            ));
    peoples.push_back(People("Anna",
                             "Tobolenko",
                             People::Gender::female,
                             Date(26, 04, 1992),
                             Passport(4448, 624472),
                             "89534210987",
                             "Russian"
                            ));
    peoples.push_back(People("David",
                             "Caldwell",
                             People::Gender::male,
                             Date(15, 05, 1983),
                             Passport(4245, 437843)
                            ));
    peoples.push_back(People("Maria",
                             "Smith",
                             People::Gender::female,
                             Date(10, 06, 2000)
                            ));
    for(int i = 0; i<30; i++)
        peoples.push_back(PeopleGenerator::getRandomPeople());
    return 0;
}
