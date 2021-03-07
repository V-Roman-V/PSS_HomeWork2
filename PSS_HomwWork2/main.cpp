#include <iostream>
#include <queue>
#include <vector>
#include <fstream>

#include "University_class/university.h"
#include "Additional_classes/peoplegenerator.h"
#include "Additional_classes/roomlocation.h"

#include <cstdlib>
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


    vector<string> courses = {" Introduction to Programming", "Analytical Geometry and Linear Algebra", "Data Structures and Algorithm", "Foreign Language", "Mathematical Analysis", "Theoretical Computer Science", "Operating Systems"};
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
    const string LINE = "---------------------------------------------------------";
    string input;
    while(true){ // position selection
        // ------------------------------
        //  где-то добавить комнаты
        // ------------------------------

        system("cls");
        cout<<"Welcome to "<<Innopolis.getName()<<endl;
        cout<<LINE<<endl;
        cout<<"Our university has:"<<endl;
        cout<<"\t"<<1<<" director"<<endl;
        cout<<"\t"<<Innopolis.getAdmins().size()<<" admins"<<endl;
        cout<<"\t"<<Innopolis.getLabEmployees().size()<<" lab employees"<<endl;
        cout<<"\t"<<Innopolis.getProfessors().size()<<" professors"<<endl;
        cout<<"\t"<<Innopolis.getStudents().size()<<" students"<<endl<<endl;
        cout<<"You can read the list in detail. \n\tPlease enter the position name {(0)director; (1)admin; (2)labEmployee; (3)professor; (4)student}"<<endl;
        cout<<'>';cin>>input;
        int position = -1;
        int command = -1;
        if((input.find_first_not_of( "0123456789" ) == std::string::npos)) command = stoi(input);
        if(input == "director" or command == 0)
            position = 0;
        if(input == "admin" or command == 1)
            position = 1;
        if(input == "labEmployee" or command == 2)
            position = 2;
        if(input == "professor" or command == 3)
            position = 3;
        if(input == "student" or command == 4)
            position = 4;
        if(position == -1) continue;
        vector<UniversityPeople*> peoples;
        switch(position){
            case 0:peoples.push_back(Innopolis.getDirector());break;
            case 1:peoples = vector<UniversityPeople*>(Innopolis.getAdmins().begin(),Innopolis.getAdmins().end());break;
            case 2:peoples = vector<UniversityPeople*>(Innopolis.getLabEmployees().begin(),Innopolis.getLabEmployees().end());break;
            case 3:peoples = vector<UniversityPeople*>(Innopolis.getProfessors().begin(),Innopolis.getProfessors().end());break;
            case 4:peoples = vector<UniversityPeople*>(Innopolis.getStudents().begin(),Innopolis.getStudents().end());break;
        }

        bool incorrect_pass = false;
        int chosen_person = 0;
        while(true){ // Person selection
            system("cls");
            switch(position){
                case 0:cout<<"Director ";break;
                case 1:cout<<"Admins ";break;
                case 2:cout<<"Lab employees ";break;
                case 3:cout<<"Professors ";break;
                case 4:cout<<"Students ";break;
            }
            cout<<"in "<<Innopolis.getName()<<":"<<endl<<endl;
            int i=1;
            for(auto p: peoples)
                cout<<" "<<i++<<") "<<p->getCommonInfo()<<endl;
            cout<<LINE<<endl;
            cout<<"You can go into detail about a particular person or go back.\n\tPlease enter the person's number in this list; To go back enter \"back\" or \"-\""<<endl;
            if(!incorrect_pass){
                cout<<'>';cin>>input;
                if(input == "back" or input == "-"){break;}
                if((input.find_first_not_of( "0123456789" ) != std::string::npos)) continue;

                int personal_num= stoi(input);
                if(personal_num <=0 || personal_num > peoples.size()) continue;
                chosen_person = personal_num;
            } else
                cout<<">"<<chosen_person<<endl;

            UniversityPeople* person = peoples[chosen_person-1];

            cout<<" "<<person->getFullInfo()<<endl;

            cout<<LINE<<endl;
            cout<<"Would you like to log in to this account?  \n\tPlease enter the {(y)Yes; No - default}";
            if(incorrect_pass)
                cout<<"  (Entered password was incorrect)";
            cout<<endl;
            cout<<'>';cin>>input;
            if(input != "Yes" && input != "y"){
                incorrect_pass = false;
                continue;
            }

            if(position == 1){
                cout<<LINE<<endl;
                cout<<"Since you are trying to log in as an administrator, you need to enter your password."<<endl;
                cout<<"\tPlease enter the password."<<endl;
                cout<<'>';cin >>input;
                Admin* admin = static_cast<Admin *>(person);
                if(!admin->checkPassword(input)){
                    incorrect_pass= true;
                    continue;
                }
            }
            incorrect_pass = false;

            while(true){
                system("cls");
                cout<<"You are login to the system as "<<person->getName()<<endl;
                cout<<"You can log out, display information about yourself, see the history of your movements, and try to enter the room."<<endl;
                cout<<"\tPlease enter the command  {(0)logOut; (1)myInfo; (2)myMovementsHistory; (3)tryOpenRoom}"<<endl;
                cout<<'>';cin>>input;
                int command = -1;
                if((input.find_first_not_of( "0123456789" ) == std::string::npos)) command = stoi(input);
                if(input == "logOut")
                    command = 0;
                if(input == "myInfo")
                    command = 1;
                if(input == "myMovementsHistory")
                    command = 2;
                if(input == "tryOpenRoom")
                    command = 3;
                if(command < 0 or 3 < command) continue;
                if(command == 0) break;
                if(command == 1) {
                    cout<<" "<<person->getFullInfo()<<endl;
                    continue;
                }
                if(command == 2) {
                    cout<<"\tMy movements history: "<<endl;
                    cout<<" "<<person->getMovementHistory()<<endl;
                    continue;
                }
                if(command != 3) continue;
                cout<<" tryOpenRoom"<<endl;

            }
        }
    }
    return 0;
}
