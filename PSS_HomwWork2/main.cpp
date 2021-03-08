#include <iostream>
#include <queue>
#include <vector>
#include <fstream>

#include "University_class/university.h"
#include "Additional_classes/peoplegenerator.h"
#include "Additional_classes/roomlocation.h"

#include <cstdlib>
#include <iomanip>

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
    Innopolis.getDirectorCabinet()->addWorker(Innopolis.getDirector());

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
        system("cls");
        cout<<"Welcome to "<<Innopolis.getName()<<endl;
        cout<<LINE<<endl;
        cout<<"Our university has:"<<endl;
        cout<<"\t"<<left<<setw(20)<<"1 director"                                                   <<"|\t"<<Innopolis.getCabinetRoom().size()<<" cabinets and 1 director's cabinet"<<endl;
        cout<<"\t"<<left<<setw(20)<<to_string(Innopolis.getAdmins().size())+" admins"              <<"|\t"<<Innopolis.getClassRoom().size()<<" class rooms"<<endl;
        cout<<"\t"<<left<<setw(20)<<to_string(Innopolis.getLabEmployees().size())+" lab employees" <<"|\t"<<Innopolis.getLectureRoom().size()<<" lecture rooms"<<endl;
        cout<<"\t"<<left<<setw(20)<<to_string(Innopolis.getProfessors().size())+" professors"      <<"|\t"<<Innopolis.getConferenceRoom().size()<<" conference rooms"<<endl;
        cout<<"\t"<<left<<setw(20)<<to_string(Innopolis.getStudents().size())+" students"          <<"|\t"<<Innopolis.getLivingRoom().size()<<" living rooms"<<endl<<endl;
        cout<<"Choose what you want to find out information about.\n\tPlease enter the {(0)People; (1)Room; (-)exit }"<<endl;
        cout<<'>';cin>>input;
        if(input == "-" or input == "exit") break;

        int sphere = -1;
        if((input.find_first_not_of( "0123456789" ) == std::string::npos)) sphere = stoi(input);
        if(input == "People")
            sphere = 0;
        if(input == "Room")
            sphere = 1;
        if(sphere< 0 or sphere > 1) continue;
        cout<<LINE<<endl;
        if(sphere == 1){ //rooms
            cout<<"You can read the list in detail. \n\tPlease enter the room type {(0)cabinet; (1)class; (2)lecture; (3)conference; (4)living}"<<endl;
            cout<<'>';cin>>input;
            int type = -1;
            if((input.find_first_not_of( "0123456789" ) == std::string::npos)) type = stoi(input);
            if(input == "cabinet")
                type = 0;
            if(input == "class")
                type = 1;
            if(input == "lecture")
                type = 2;
            if(input == "conference")
                type = 3;
            if(input == "living")
                type = 4;
            if(type< 0 or type > 4) continue;
            vector<Room*> rooms;
            switch(type){
                case 0:rooms = vector<Room*>(Innopolis.getCabinetRoom().begin(),Innopolis.getCabinetRoom().end()); rooms.push_back(Innopolis.getDirectorCabinet());break;
                case 1:rooms = vector<Room*>(Innopolis.getClassRoom().begin(),Innopolis.getClassRoom().end());break;
                case 2:rooms = vector<Room*>(Innopolis.getLectureRoom().begin(),Innopolis.getLectureRoom().end());break;
                case 3:rooms = vector<Room*>(Innopolis.getConferenceRoom().begin(),Innopolis.getConferenceRoom().end());break;
                case 4:rooms = vector<Room*>(Innopolis.getLivingRoom().begin(),Innopolis.getLivingRoom().end());break;
            }
            int i=1;
            for(auto r: rooms)
                cout<<" "<<i++<<") "<<r->getInfo()<<endl;
            cout<<LINE<<endl;
            cout<<"return back. Press ENTER"<<endl;
            cin.get();
            getline(cin,input);
            continue;
        }

        cout<<"You can read the list in detail. \n\tPlease enter the position name {(0)director; (1)admin; (2)labEmployee; (3)professor; (4)student}"<<endl;
        cout<<'>';cin>>input;
        int position = -1;
        if((input.find_first_not_of( "0123456789" ) == std::string::npos)) position = stoi(input);
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
        if(position< 0 or position > 4) continue;
        vector<UniversityPeople*> peoples;
        bool isAdmin = false;
        switch(position){
            case 0:peoples.push_back(Innopolis.getDirector());break;
            case 1:peoples = vector<UniversityPeople*>(Innopolis.getAdmins().begin(),Innopolis.getAdmins().end()); isAdmin = true; break;
            case 2:peoples = vector<UniversityPeople*>(Innopolis.getLabEmployees().begin(),Innopolis.getLabEmployees().end()); break;
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

            if(isAdmin){
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

            int giveAccessPhase = -1;
            UniversityPeople* selected_person = nullptr;
            UniversityRoom*   selected_room = nullptr;
            AccessLevel       selected_level = AccessLevel::no_level;
            while(true){
                system("cls");
                cout<<"You are login to the system as "<<person->getName() <<((isAdmin)?" (Administrator)":"")<<endl;
                cout<<"You can log out, display information about yourself, see the history of your movements, and try to enter the room."<<endl;
                cout<<"\tPlease enter the command  {(0)logOut; (1)myInfo; (2)myMovementsHistory; (3)tryOpenRoom"<<((isAdmin)?"; (4)giveAccess":"")<<"}"<<endl;
                //----- give access phase
                if(giveAccessPhase == 0){ // chosen person
                    cout<<">4"<<endl;
                    cout<<LINE<<endl;
                    cout<<"Choose the person you want to give access."<<endl;
                    cout<<"\tPlease enter the position name {(0)admin; (1)labEmployee; (2)professor; (3)student}"<<endl;
                    cout<<'>';cin>>input;
                    int position = -1;
                    if((input.find_first_not_of( "0123456789" ) == std::string::npos)) position = stoi(input);
                    if(input == "admin")
                        position = 0;
                    if(input == "labEmployee")
                        position = 1;
                    if(input == "professor")
                        position = 2;
                    if(input == "student")
                        position = 3;
                    if(position< 0 or position > 3) {giveAccessPhase = -1;continue;}
                    vector<UniversityPeople*> peoples;
                    switch(position){
                        case 0:peoples = vector<UniversityPeople*>(Innopolis.getAdmins().begin(),Innopolis.getAdmins().end()); break;
                        case 1:peoples = vector<UniversityPeople*>(Innopolis.getLabEmployees().begin(),Innopolis.getLabEmployees().end()); break;
                        case 2:peoples = vector<UniversityPeople*>(Innopolis.getProfessors().begin(),Innopolis.getProfessors().end());break;
                        case 3:peoples = vector<UniversityPeople*>(Innopolis.getStudents().begin(),Innopolis.getStudents().end());break;
                    }
                    while(true){ // Person selection to give access
                        system("cls");
                        switch(position){
                            case 0:cout<<"Admins:";break;
                            case 1:cout<<"Lab employees:";break;
                            case 2:cout<<"Professors:";break;
                            case 3:cout<<"Students:";break;
                        }
                        cout<<endl<<endl;
                        int i=1;
                        for(auto p: peoples)
                            cout<<" "<<i++<<") "<<p->getCommonInfo()<<endl;
                        cout<<LINE<<endl;
                        cout<<"Choose the person you want to give access. \n\tPlease enter the person's number in this list; To go back enter \"back\" or \"-\""<<endl;
                        cout<<'>';cin>>input;
                        if(input == "back" or input == "-"){giveAccessPhase = -1;break;}
                        if((input.find_first_not_of( "0123456789" ) != std::string::npos)) continue;

                        int personal_num = stoi(input);
                        if(personal_num <=0 || personal_num > peoples.size()) continue;
                        chosen_person = personal_num;

                        selected_person = peoples[chosen_person-1];
                        giveAccessPhase = 1;
                        break;
                    }
                    continue;
                }
                if(giveAccessPhase == 1){
                    cout<<">4"<<endl;
                    cout<<LINE<<endl;
                    cout<<"Selected person: "<<selected_person->getCommonInfo()<<endl;
                    cout<<LINE<<endl;
                    cout<<"Choose what you want to give the person."<<endl;
                    cout<<"\tPlease enter the type {(0)room; (1)accessLevel; (-)back}"<<endl;
                    cout<<'>';cin>>input;
                    if(input == "back" or input == "-"){giveAccessPhase = -1;continue;}
                    int Atype = -1;
                    if((input.find_first_not_of( "0123456789" ) == std::string::npos)) Atype = stoi(input);
                    if(input == "room")
                        Atype = 0;
                    if(input == "accessLevel")
                        Atype = 1;
                    if(Atype<0 or 1<Atype)continue;
                    if(Atype == 1){
                        cout<<LINE<<endl;
                        cout<<"Choose the level you want to give the person."<<endl;
                        cout<<"\tPlease enter the level {(0)noLevel; (1)green; (2)yellow; (3)red; (4)black}"<<endl;
                        cout<<'>';cin>>input;
                        int access = -1;
                        if((input.find_first_not_of( "0123456789" ) == std::string::npos)) access = stoi(input);
                        if(input == "noLevel")
                            access = 0;
                        if(input == "green")
                            access = 1;
                        if(input == "yellow")
                            access = 2;
                        if(input == "red")
                            access = 3;
                        if(input == "black")
                            access = 4;
                        if(access<0 or 4<access)continue;
                        switch (access) {
                            case 0:selected_level = AccessLevel::no_level;break;
                            case 1:selected_level = AccessLevel::green;break;
                            case 2:selected_level = AccessLevel::yellow;break;
                            case 3:selected_level = AccessLevel::red;break;
                            case 4:selected_level = AccessLevel::black;break;
                        }
                        giveAccessPhase = 2;
                        continue;
                    }
                    if(Atype != 0)continue;
                    cout<<LINE<<endl;
                    cout<<"Choose the room type you want to give access to the person."<<endl;
                    cout<<"\tPlease enter the room type {(0)cabinet; (1)class; (2)lecture; (3)conference}"<<endl;
                    cout<<'>';cin>>input;
                    int type = -1;
                    if((input.find_first_not_of( "0123456789" ) == std::string::npos)) type = stoi(input);
                    if(input == "cabinet")
                        type = 0;
                    if(input == "class")
                        type = 1;
                    if(input == "lecture")
                        type = 2;
                    if(input == "conference")
                        type = 3;
                    if(type< 0 or type > 3) continue;
                    vector<UniversityRoom*> rooms;
                    switch(type){
                        case 0:rooms = vector<UniversityRoom*>(Innopolis.getCabinetRoom().begin(),Innopolis.getCabinetRoom().end()); rooms.push_back(Innopolis.getDirectorCabinet());break;
                        case 1:rooms = vector<UniversityRoom*>(Innopolis.getClassRoom().begin(),Innopolis.getClassRoom().end());break;
                        case 2:rooms = vector<UniversityRoom*>(Innopolis.getLectureRoom().begin(),Innopolis.getLectureRoom().end());break;
                        case 3:rooms = vector<UniversityRoom*>(Innopolis.getConferenceRoom().begin(),Innopolis.getConferenceRoom().end());break;
                    }
                    while(true) {
                        system("cls");
                        switch(type){
                            case 0:cout<<"Cabinets:";break;
                            case 1:cout<<"Class rooms:";break;
                            case 2:cout<<"Lecture rooms:";break;
                            case 3:cout<<"Conference rooms:";break;
                        }
                        cout<<endl;

                        int i=1;
                        for(auto r: rooms)
                            cout<<" "<<i++<<") "<<r->getInfo()<<endl;
                        cout<<LINE<<endl;
                        cout<<"Choose the number of the room you want to give access to the person or go back. \n\tPlease enter the room number in this list; To go back enter \"back\" or \"-\""<<endl;
                        cout<<'>';cin>>input;
                        if(input == "back" or input == "-"){break;}
                        if((input.find_first_not_of( "0123456789" ) != std::string::npos)) continue;
                        int room_num= stoi(input);
                        if(room_num <=0 || room_num > rooms.size()) continue;
                        selected_room =  rooms[room_num-1];
                        giveAccessPhase = 3;
                        break;
                    }
                    continue;
                }
                if(giveAccessPhase == 2){
                    cout<<">4"<<endl;
                    cout<<LINE<<endl;
                    cout<<"Selected person: "<<selected_person->getCommonInfo()<<endl;
                    cout<<LINE<<endl;
                    cout<<"Selected new access level: "<<getAccessLevelName(selected_level)<<endl;
                    cout<<LINE<<endl;
                    cout<<"Confirm your choice or cancel it\n\tPlease enter the {(0)confirm; (1)cancel}"<<endl;
                    cout<<'>';cin>>input;
                    int confirm = -1;
                    if((input.find_first_not_of( "0123456789" ) == std::string::npos)) confirm = stoi(input);
                    if(input == "confirm")
                        confirm = 0;
                    if(input == "cancel")
                        confirm = 1;
                    if(confirm < 0 or 1< confirm) continue;
                    if(confirm == 0){
                        Admin* admin = static_cast<Admin*>(person);
                        admin->giveAccess(selected_person,selected_level);
                        cout<<"The level was successfully assigned"<<endl;
                    }
                    if(confirm == 1){
                        cout<<"The level has not been assigned"<<endl;
                    }
                    giveAccessPhase = -1;
                    cout<<"return back. Press ENTER"<<endl;
                    cin.get();
                    getline(cin,input);
                    continue;
                }
                if(giveAccessPhase == 3){
                    cout<<">4"<<endl;
                    cout<<LINE<<endl;
                    cout<<"Selected person: "<<selected_person->getCommonInfo()<<endl;
                    cout<<LINE<<endl;
                    cout<<"Selected room: "<<endl<<selected_room->getInfo()<<endl;
                    cout<<LINE<<endl;
                    cout<<"Confirm your choice or cancel it\n\tPlease enter the {(0)confirm; (1)cancel}"<<endl;
                    cout<<'>';cin>>input;
                    int confirm = -1;
                    if((input.find_first_not_of( "0123456789" ) == std::string::npos)) confirm = stoi(input);
                    if(input == "confirm")
                        confirm = 0;
                    if(input == "cancel")
                        confirm = 1;
                    if(confirm < 0 or 1< confirm) continue;
                    if(confirm == 0){
                        Admin* admin = static_cast<Admin*>(person);
                        admin->giveAccess(selected_person,selected_room);
                        cout<<"Special access to the room was successfully assigned"<<endl;
                    }
                    if(confirm == 1){
                        cout<<"Special access to the room was not assignedd"<<endl;
                    }
                    giveAccessPhase = -1;
                    cout<<"return back. Press ENTER"<<endl;
                    cin.get();
                    getline(cin,input);
                    continue;
                }
                //----- chosen commands
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
                if(input == "giveAccess")
                    command = 4;
                if(command < 0 or ((isAdmin)?4:3) < command) continue;

                if(command == 0) break;
                if(command == 1) {
                    cout<<" "<<person->getFullInfo()<<endl;
                    cout<<"return back. Press ENTER"<<endl;
                    cin.get();
                    getline(cin,input);
                    continue;
                }
                if(command == 2) {
                    cout<<"\tMy movements history: "<<endl;
                    cout<<" "<<person->getMovementHistory()<<endl;
                    cout<<"return back. Press ENTER"<<endl;
                    cin.get();
                    getline(cin,input);
                    continue;
                }
                if(command == 3){
                    cout<<LINE<<endl;
                    cout<<"You can try to open one of the university rooms. Your access level: "<<person->getAccessLevel()<<endl;
                    cout<<"\tPlease enter the room type {(0)cabinet = "<<Cabinet::getNeededLevel()<<"; (1)class = "<<ClassRoom::getNeededLevel()<<"; (2)lecture = "<<LectureRoom::getNeededLevel()<<"; (3)conference = "<<ConferenceRoom::getNeededLevel()<<"}"<<endl;
                    cout<<'>';cin>>input;
                    int type = -1;
                    if((input.find_first_not_of( "0123456789" ) == std::string::npos)) type = stoi(input);
                    if(input == "cabinet")
                        type = 0;
                    if(input == "class")
                        type = 1;
                    if(input == "lecture")
                        type = 2;
                    if(input == "conference")
                        type = 3;
                    if(type< 0 or type > 3) continue;
                    vector<UniversityRoom*> rooms;
                    switch(type){
                        case 0:rooms = vector<UniversityRoom*>(Innopolis.getCabinetRoom().begin(),Innopolis.getCabinetRoom().end()); rooms.push_back(Innopolis.getDirectorCabinet());break;
                        case 1:rooms = vector<UniversityRoom*>(Innopolis.getClassRoom().begin(),Innopolis.getClassRoom().end());break;
                        case 2:rooms = vector<UniversityRoom*>(Innopolis.getLectureRoom().begin(),Innopolis.getLectureRoom().end());break;
                        case 3:rooms = vector<UniversityRoom*>(Innopolis.getConferenceRoom().begin(),Innopolis.getConferenceRoom().end());break;
                    }
                    while(true) { // trying open room
                        system("cls");
                        switch(type){
                            case 0:cout<<"Cabinets:";break;
                            case 1:cout<<"Class rooms:";break;
                            case 2:cout<<"Lecture rooms:";break;
                            case 3:cout<<"Conference rooms:";break;
                        }
                        cout<<endl;

                        int i=1;
                        for(auto r: rooms)
                            cout<<" "<<i++<<") "<<r->getInfo()<<endl;
                        cout<<LINE<<endl;
                        cout<<"Choose the number of the room you want to open or go back.\n\tPlease enter the room's number in this list; To go back enter \"back\" or \"-\""<<endl;
                        cout<<'>';cin>>input;
                        if(input == "back" or input == "-"){break;}
                        if((input.find_first_not_of( "0123456789" ) != std::string::npos)) continue;
                        int room_num= stoi(input);
                        if(room_num <=0 || room_num > rooms.size()) continue;
                        bool open = person->tryToEnter(rooms[room_num-1]);
                        cout<<LINE<<endl;
                        if(open)
                            cout<<"You were able to open the door"<<endl;
                        else
                            cout<<"You do not have permission to open this room"<<endl;
                        cout<<"return back. Press ENTER"<<endl;
                        cin.get();
                        getline(cin,input);

                        break;
                    }
                    continue;
                }
                if(command != 4) continue;
                giveAccessPhase = 0;
            }
        }
    }
    return 0;
}
