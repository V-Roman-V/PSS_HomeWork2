#include <iostream>
#include <queue>
#include <vector>
#include "University_class/university.h"
#include "Additional_classes/peoplegenerator.h"
#include "Additional_classes/roomlocation.h"
using namespace std;

template<class T>
struct myQueue : public queue<T>{
    T pickLast(){T item = this->front(); this->pop();return item;}
};

int main()
{
    University Innopolis("Innopolis University");
    // ---------------------------------------------------------- Declare people
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

// ---------------------------------------------------------- Add peoples
    Innopolis.setDirector(peoples.pickLast());

    for(int i=0;i<2;i++)
        Innopolis.addAdmin(peoples.pickLast());

    for(int i=0;i<4;i++)
        Innopolis.addEmployess(peoples.pickLast());


    vector<string> courses = {"PSS", "AGLA", "DSA", "FL", "MA", "TCS", "OS"};
    for(int i=0;i<8;i++)
        Innopolis.addProfessor(peoples.pickLast(), nullptr, courses[ i%courses.size()]);

    while(!peoples.empty())
        Innopolis.addStudent(peoples.pickLast(), nullptr, (rand()%4+1));
// ---------------------------------------------------------- Declare Room
    myQueue<RoomLocation> university_locations;

    for(int i=0;i<8;i++)
        university_locations.emplace(RoomLocation::Place::university, 1, 100+i);
    for(int i=0;i<10;i++)
        university_locations.emplace(RoomLocation::Place::university, 2, 200+i);
    for(int i=0;i<10;i++)
        university_locations.emplace(RoomLocation::Place::university, 3, 300+i);

    myQueue<RoomLocation> campuse_locations;
    for(int i=0;i<6;i++)
        campuse_locations.emplace(RoomLocation::Place::campuse, 1, i, 1);
    for(int i=0;i<6;i++)
        campuse_locations.emplace(RoomLocation::Place::campuse, 1, i, 2);

// ---------------------------------------------------------- Add Rooms
    Innopolis.setDirectorCabinet(university_locations.pickLast());

    for(int i=0;i<6;i++)
        Innopolis.addLectureRoom(university_locations.pickLast());

    for(int i=0;i<6;i++)
        Innopolis.addCabinet(university_locations.pickLast());

    for(int i=0;i<6;i++)
        Innopolis.addConferenceRoom(university_locations.pickLast());

    while(!university_locations.empty())
        Innopolis.addClassRoom(university_locations.pickLast());

    while(!campuse_locations.empty())
        Innopolis.addLivingRoom(campuse_locations.pickLast());


// ----------------------------------------------------------
    cout<<Innopolis.getListPeoples();
    cout<<"___________________________________"<<endl;
    cout<<Innopolis.getListRooms();
    return 0;
}
