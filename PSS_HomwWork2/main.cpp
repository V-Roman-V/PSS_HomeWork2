#include <iostream>
#include <queue>
#include <vector>
#include "University_class/university.h"
#include "Additional_classes/peoplegenerator.h"
using namespace std;

template<class T>
struct myQueue : public queue<T>{
    T pickLast(){T item = this->front(); this->pop();return item;}
};

int main()
{
    University Innopolis("Innopolis University");
    myQueue<People> peoples;
    peoples.emplace("Donald",
                     "Park",
                     People::Gender::male,
                     Date(06, 03, 1989),
                     Passport(4767, 235646),
                     "89534210987",
                     "American"
                    );
    peoples.emplace("Anna",
                     "Tobolenko",
                     People::Gender::female,
                     Date(26, 04, 1992),
                     Passport(4448, 624472),
                     "89534210987",
                     "Russian"
                    );
    peoples.emplace("David",
                     "Caldwell",
                     People::Gender::male,
                     Date(15, 05, 1983),
                     Passport(4245, 437843)
                    );
    peoples.emplace("Maria",
                     "Smith",
                     People::Gender::female,
                     Date(10, 06, 2000)
                    );
    for(int i = 0; i<30; i++)
        peoples.emplace(PeopleGenerator::getRandomPeople());

// ----------------------------------------------------------
    Innopolis.setDirector(peoples.pickLast());

    for(int i=1;i<=2;i++)
        Innopolis.addAdmin(peoples.pickLast());

    for(int i=1;i<=4;i++)
        Innopolis.addEmployess(peoples.pickLast());

    for(int i=1;i<=8;i++)
        Innopolis.addProfessor(peoples.pickLast(), nullptr, "PSS");

    for(int i=1;i<=16;i++)
        Innopolis.addStudent(peoples.pickLast(), nullptr, (rand()%4+1));
// ----------------------------------------------------------
    cout<<Innopolis.getListPeoples();
    return 0;
}
