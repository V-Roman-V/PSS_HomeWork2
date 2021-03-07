#include <iostream>
#include <queue>
#include <vector>
#include <fstream>

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
    ofstream out("out.txt");
//    cout<<(out.is_open()?"opened out.txt file":"output file doesn't open")<<endl;

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
    for(int i = 0; i<33; i++)
        peoples.emplace(PeopleGenerator::getRandomPeople());

// ---------------------------------------------------------- Add peoples
    Innopolis.setDirector(peoples.pickLast());

    Innopolis.addAdmin(peoples.pickLast(),"password");
    Innopolis.addAdmin(peoples.pickLast(),"12345");

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
        Innopolis.addLectureRoom(university_locations.pickLast(), ((rand()%2)?120:180));

    for(int i=0;i<6;i++)
        Innopolis.addCabinet(university_locations.pickLast(), (3+rand()%3));

    for(int i=0;i<6;i++)
        Innopolis.addConferenceRoom(university_locations.pickLast(), 12);

    while(!university_locations.empty())
        Innopolis.addClassRoom(university_locations.pickLast());

    while(!campuse_locations.empty())
        Innopolis.addLivingRoom(campuse_locations.pickLast(), 2 + rand()%4);

// ---------------------------------------------------------- Make link between cabinets and professors/lab_employess
{
    auto professors = Innopolis.getProfessors();
    auto employess = Innopolis.getLabEmployees();

    auto cabinets = Innopolis.getCabinetRoom();
    int num_cab = 0;
    for(int i=0;i<professors.size();i++){
        if(num_cab >= cabinets.size())break;
        if(cabinets[num_cab]->getCountWorkers() < cabinets[num_cab]->getMaxPeople())
            cabinets[num_cab]->addWorker(professors[i]);
        else{
            num_cab++;
            i--;
        }
    }
    num_cab++;
    for(int i=0;i<employess.size();i++){
        if(num_cab >= cabinets.size())break;
        if(cabinets[num_cab]->getCountWorkers() < cabinets[num_cab]->getMaxPeople())
            cabinets[num_cab]->addWorker(employess[i]);
        else{
            num_cab++;
            i--;
        }
    }
}
// ----------------------------------------------------------  Make link between livingRoom and students
{
    auto students = Innopolis.getStudents();
    auto living = Innopolis.getLivingRoom();
    int num_liv = 0;
    for(int i=0;i<students.size();i++){
        if(num_liv >= living.size())break;
        if(living[num_liv]->getCountResidents() < living[num_liv]->getMaxPeople())
            living[num_liv]->addResidents(students[i]);
        else{
            num_liv++;
            i--;
        }
    }
}
// ----------------------------------------------------------

    out<<Innopolis.getFullListPeoples();
    out<<"___________________________________"<<endl;
    out<<Innopolis.getCommonListPeoples();
    out<<"___________________________________"<<endl;
    out<<Innopolis.getListRooms();
    out<<"___________________________________"<<endl;
// ----------------------------------------------------------

    string input;
    cout<<"Welcome to "<<Innopolis.getName()<<endl;
    while(true){ // position selection
        cout<<"Our university has:"<<endl;
        cout<<"\t"<<1<<" director"<<endl;
        cout<<"\t"<<Innopolis.getAdmins().size()<<" admins"<<endl;
        cout<<"\t"<<Innopolis.getLabEmployees().size()<<" lab employees"<<endl;
        cout<<"\t"<<Innopolis.getProfessors().size()<<" professors"<<endl;
        cout<<"\t"<<Innopolis.getStudents().size()<<" students"<<endl<<endl;
        cout<<"You can read the list in detail. \n\tPlease enter the position name {director;admin;labEmployee;professor;student}"<<endl;
        cin>>input;
        int position = -1;
        if(input == "director")
            position = 0;
        if(input == "admin")
            position = 1;
        if(input == "labEmployee")
            position = 2;
        if(input == "professor")
            position = 3;
        if(input == "student")
            position = 4;
        if(position == -1) continue;
        vector<const UniversityPeople*> peoples;
        switch(position){
            case 0:peoples.push_back(Innopolis.getDirector());break;
            case 1:peoples = vector<const UniversityPeople*>(Innopolis.getAdmins().begin(),Innopolis.getAdmins().end());break;
            case 2:peoples = vector<const UniversityPeople*>(Innopolis.getLabEmployees().begin(),Innopolis.getLabEmployees().end());break;
            case 3:peoples = vector<const UniversityPeople*>(Innopolis.getProfessors().begin(),Innopolis.getProfessors().end());break;
            case 4:peoples = vector<const UniversityPeople*>(Innopolis.getStudents().begin(),Innopolis.getStudents().end());break;
        }
        int i=1;
        for(auto p: peoples)
            cout<<" "<<i++<<") "<<p->getCommonInfo()<<endl;
        while(true){ // person chosen
            cout<<"You can go into detail about a particular person or go back.\n\tPlease enter the person's personal id or enter \"back\""<<endl;
            cin>>input;
            if(input == "back"){cout<<"-------------------------------------------------------"<<endl;break;}
            if((input.find_first_not_of( "0123456789" ) != std::string::npos)) continue;

            int personal_id= stoi(input);
            const UniversityPeople* person = nullptr;
            for(auto p: peoples)
                if(p->getPersonalId() == personal_id)
                    person = p;
            if(person == nullptr) continue;

            cout<<" "<<person->getFullInfo()<<endl;


        }
    }
    return 0;
}
