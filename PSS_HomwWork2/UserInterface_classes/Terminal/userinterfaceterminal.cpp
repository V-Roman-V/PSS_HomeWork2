#include "userinterfaceterminal.h"

const std::string UserInterfaceTerminal::LINE = "---------------------------------------------------------";

using namespace std;
void UserInterfaceTerminal::start(University& university)
{
    string input;
    while(true){ // position selection
        clear();
        printWelcomeText(university);
        getInput(input);
        if(input == "-" or input == "exit") break;

        int sphere = calculateInput(input,{"People","Room"});
        if( sphere == -1) continue;
        printSeparator();
        if(sphere == 1){ //rooms
            cout<<"You can read the list in detail. \n\tPlease enter the room type {(0)cabinet; (1)class; (2)lecture; (3)conference; (4)living}"<<endl;
            getInput(input);
            int type = calculateInput(input,{"cabinet","class","lecture","conference","living"});
            if( type == -1) continue;
            vector<Room*> rooms;
            switch(type){
                case 0:rooms = vector<Room*>(university.getCabinetRoom().begin(),university.getCabinetRoom().end()); rooms.push_back(university.getDirectorCabinet());break;
                case 1:rooms = vector<Room*>(university.getClassRoom().begin(),university.getClassRoom().end());break;
                case 2:rooms = vector<Room*>(university.getLectureRoom().begin(),university.getLectureRoom().end());break;
                case 3:rooms = vector<Room*>(university.getConferenceRoom().begin(),university.getConferenceRoom().end());break;
                case 4:rooms = vector<Room*>(university.getLivingRoom().begin(),university.getLivingRoom().end());break;
            }
            int i=1;
            for(auto r: rooms)
                cout<<" "<<i++<<") "<<r->getInfo()<<endl;
            printSeparator();
            waitENTER();
            continue;
        }

        cout<<"You can read the list in detail. \n\tPlease enter the position name {(0)director; (1)admin; (2)labEmployee; (3)professor; (4)student}"<<endl;
        getInput(input);
        int position = calculateInput(input,{"director","admin","labEmployee","professor","student"});
        if(position == -1) continue;
        vector<UniversityPeople*> peoples;
        bool isAdmin = false;
        switch(position){
            case 0:peoples.push_back(university.getDirector());break;
            case 1:peoples = vector<UniversityPeople*>(university.getAdmins().begin(),university.getAdmins().end()); isAdmin = true; break;
            case 2:peoples = vector<UniversityPeople*>(university.getLabEmployees().begin(),university.getLabEmployees().end()); break;
            case 3:peoples = vector<UniversityPeople*>(university.getProfessors().begin(),university.getProfessors().end());break;
            case 4:peoples = vector<UniversityPeople*>(university.getStudents().begin(),university.getStudents().end());break;
        }

        bool incorrect_pass = false;
        int chosen_person = 0;
        while(true){ // Person selection
            clear();
            switch(position){
                case 0:cout<<"Director ";break;
                case 1:cout<<"Admins ";break;
                case 2:cout<<"Lab employees ";break;
                case 3:cout<<"Professors ";break;
                case 4:cout<<"Students ";break;
            }
            cout<<"in "<<university.getName()<<":"<<endl<<endl;
            int i=1;
            for(auto p: peoples)
                cout<<" "<<i++<<") "<<p->getCommonInfo()<<endl;
            printSeparator();
            cout<<"You can go into detail about a particular person or go back.\n\tPlease enter the person's number in this list; To go back enter \"back\" or \"-\""<<endl;
            if(!incorrect_pass){
                getInput(input);
                if(input == "back" or input == "-"){break;}
                if(!isNumber(input)) continue;

                unsigned int personal_num= stoi(input);
                if(personal_num <=0 || personal_num > peoples.size()) continue;
                chosen_person = personal_num;
            } else
                cout<<">"<<chosen_person<<endl;

            UniversityPeople* person = peoples[chosen_person-1];

            cout<<" "<<person->getFullInfo()<<endl;

            printSeparator();
            cout<<"Would you like to log in to this account?  \n\tPlease enter the {(y)Yes; No - default}";
            if(incorrect_pass)
                cout<<"  (Entered password was incorrect)";
            cout<<endl;
            getInput(input);
            if(input != "Yes" && input != "y"){
                incorrect_pass = false;
                continue;
            }

            if(isAdmin){
                printSeparator();
                cout<<"Since you are trying to log in as an administrator, you need to enter your password."<<endl;
                cout<<"\tPlease enter the password."<<endl;
                getInput(input);
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
                clear();
                cout<<"You are login to the system as "<<person->getName() <<((isAdmin)?" (Administrator)":"")<<endl;
                cout<<"You can log out, display information about yourself, see the history of your movements,"<<(isAdmin?"":" and")<<" try to enter the room"<<(isAdmin?", and give access to people.":".")<<endl;
                cout<<"\tPlease enter the command  {(0)logOut; (1)myInfo; (2)myMovementsHistory; (3)tryOpenRoom"<<((isAdmin)?"; (4)giveAccess":"")<<"}"<<endl;
                //----- give access phase
                if(giveAccessPhase == 0){ // chosen person
                    cout<<">4"<<endl;
                    printSeparator();
                    cout<<"Choose the person you want to give access."<<endl;
                    cout<<"\tPlease enter the position name {(0)admin; (1)labEmployee; (2)professor; (3)student}"<<endl;
                    getInput(input);
                    int position = calculateInput(input,{"admin","labEmployee","professor","student"});
                    if( position == -1) {giveAccessPhase = -1;continue;}

                    vector<UniversityPeople*> peoples;
                    switch(position){
                        case 0:peoples = vector<UniversityPeople*>(university.getAdmins().begin(),university.getAdmins().end()); break;
                        case 1:peoples = vector<UniversityPeople*>(university.getLabEmployees().begin(),university.getLabEmployees().end()); break;
                        case 2:peoples = vector<UniversityPeople*>(university.getProfessors().begin(),university.getProfessors().end());break;
                        case 3:peoples = vector<UniversityPeople*>(university.getStudents().begin(),university.getStudents().end());break;
                    }
                    while(true){ // Person selection to give access
                        clear();
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
                        printSeparator();
                        cout<<"Choose the person you want to give access. \n\tPlease enter the person's number in this list; To go back enter \"back\" or \"-\""<<endl;
                        getInput(input);
                        if(input == "back" or input == "-"){giveAccessPhase = -1;break;}
                        if(!isNumber(input)) continue;

                        unsigned int personal_num = stoi(input);
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
                    printSeparator();
                    cout<<"Selected person: "<<selected_person->getCommonInfo()<<endl;
                    printSeparator();
                    cout<<"Choose what you want to give the person."<<endl;
                    cout<<"\tPlease enter the type {(0)room; (1)accessLevel; (-)back}"<<endl;
                    getInput(input);
                    if(input == "back" or input == "-"){giveAccessPhase = -1;continue;}
                    int Atype = calculateInput(input,{"room","accessLevel"});
                    if( Atype == -1) continue;
                    if(Atype == 1){
                        printSeparator();
                        cout<<"Choose the level you want to give the person."<<endl;
                        cout<<"\tPlease enter the level {(0)noLevel; (1)green; (2)yellow; (3)red; (4)black}"<<endl;
                        getInput(input);
                        int access = calculateInput(input,{"noLevel","green","yellow","red","black"});
                        if( access == -1) continue;

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
                    printSeparator();
                    cout<<"Choose the room type you want to give access to the person."<<endl;
                    cout<<"\tPlease enter the room type {(0)cabinet; (1)class; (2)lecture; (3)conference}"<<endl;
                    getInput(input);
                    int type = calculateInput(input,{"cabinet","class","lecture","conference"});
                    if( type == -1) continue;
                    vector<UniversityRoom*> rooms;
                    switch(type){
                        case 0:rooms = vector<UniversityRoom*>(university.getCabinetRoom().begin(),university.getCabinetRoom().end()); rooms.push_back(university.getDirectorCabinet());break;
                        case 1:rooms = vector<UniversityRoom*>(university.getClassRoom().begin(),university.getClassRoom().end());break;
                        case 2:rooms = vector<UniversityRoom*>(university.getLectureRoom().begin(),university.getLectureRoom().end());break;
                        case 3:rooms = vector<UniversityRoom*>(university.getConferenceRoom().begin(),university.getConferenceRoom().end());break;
                    }
                    while(true) {
                        clear();
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
                        printSeparator();
                        cout<<"Choose the number of the room you want to give access to the person or go back. \n\tPlease enter the room number in this list; To go back enter \"back\" or \"-\""<<endl;
                        getInput(input);
                        if(input == "back" or input == "-"){break;}
                        if(!isNumber(input)) continue;
                        unsigned int room_num= stoi(input);
                        if(room_num <=0 || room_num > rooms.size()) continue;
                        selected_room =  rooms[room_num-1];
                        giveAccessPhase = 3;
                        break;
                    }
                    continue;
                }
                if(giveAccessPhase == 2){
                    cout<<">4"<<endl;
                    printSeparator();
                    cout<<"Selected person:\n"<<selected_person->getCommonInfo()<<endl;
                    printSeparator();
                    cout<<"Selected new access level: "<<getAccessLevelName(selected_level)<<endl;
                    printSeparator();
                    cout<<"Confirm your choice or cancel it\n\tPlease enter the {(0)confirm; (1)cancel}"<<endl;
                    getInput(input);
                    int confirm = calculateInput(input,{"confirm","cancel"});
                    if( confirm == -1) continue;
                    if( confirm == 0){
                        Admin* admin = static_cast<Admin*>(person);
                        admin->giveAccess(selected_person,selected_level);
                        cout<<"The level was successfully assigned"<<endl;
                    }
                    if(confirm == 1){
                        cout<<"The level has not been assigned"<<endl;
                    }
                    giveAccessPhase = -1;
                    waitENTER();
                    continue;
                }
                if(giveAccessPhase == 3){
                    cout<<">4"<<endl;
                    printSeparator();
                    cout<<"Selected person: "<<selected_person->getCommonInfo()<<endl;
                    printSeparator();
                    cout<<"Selected room: "<<endl<<selected_room->getInfo()<<endl;
                    printSeparator();
                    cout<<"Confirm your choice or cancel it\n\tPlease enter the {(0)confirm; (1)cancel}"<<endl;
                    getInput(input);
                    int confirm = calculateInput(input,{"confirm","cancel"});
                    if( confirm == -1) continue;
                    if(confirm == 0){
                        Admin* admin = static_cast<Admin*>(person);
                        admin->giveAccess(selected_person,selected_room);
                        cout<<"Special access to the room was successfully assigned"<<endl;
                    }
                    if(confirm == 1){
                        cout<<"Special access to the room was not assignedd"<<endl;
                    }
                    giveAccessPhase = -1;
                    waitENTER();
                    continue;
                }
                //----- chosen commands
                getInput(input);
                int command = calculateInput(input,{"logOut","myInfo","myMovementsHistory","tryOpenRoom","giveAccess"});
                if( command == -1) continue;
                if( command == 4 && !isAdmin) continue;

                if(command == 0) break;
                if(command == 1) {
                    cout<<" "<<person->getFullInfo()<<endl;
                    waitENTER();
                    continue;
                }
                if(command == 2) {
                    cout<<"\tMy movements history: "<<endl;
                    cout<<" "<<person->getMovementHistory()<<endl;
                    waitENTER();
                    continue;
                }
                if(command == 3){
                    printSeparator();
                    cout<<"You can try to open one of the university rooms. Your access level: "<<person->getAccessLevel()<<endl;
                    cout<<"\tPlease enter the room type {(0)cabinet = "<<Cabinet::getNeededLevel()<<"; (1)class = "<<ClassRoom::getNeededLevel()<<"; (2)lecture = "<<LectureRoom::getNeededLevel()<<"; (3)conference = "<<ConferenceRoom::getNeededLevel()<<"}"<<endl;
                    getInput(input);
                    int type = calculateInput(input,{"cabinet","class","lecture","conference"});
                    if( type == -1) continue;
                    vector<UniversityRoom*> rooms;
                    switch(type){
                        case 0:rooms = vector<UniversityRoom*>(university.getCabinetRoom().begin(),university.getCabinetRoom().end()); rooms.push_back(university.getDirectorCabinet());break;
                        case 1:rooms = vector<UniversityRoom*>(university.getClassRoom().begin(),university.getClassRoom().end());break;
                        case 2:rooms = vector<UniversityRoom*>(university.getLectureRoom().begin(),university.getLectureRoom().end());break;
                        case 3:rooms = vector<UniversityRoom*>(university.getConferenceRoom().begin(),university.getConferenceRoom().end());break;
                    }
                    while(true) { // trying open room
                        clear();
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
                        printSeparator();
                        cout<<"Choose the number of the room you want to open or go back.\n\tPlease enter the room's number in this list; To go back enter \"back\" or \"-\""<<endl;
                        getInput(input);
                        if(input == "back" or input == "-"){break;}
                        if(!isNumber(input)) continue;
                        unsigned int room_num = stoi(input);
                        if(room_num <=0 || room_num > rooms.size()) continue;
                        bool open = person->tryToEnter(rooms[room_num-1]);
                        printSeparator();
                        if(open)
                            cout<<"You were able to open the door"<<endl;
                        else
                            cout<<"You do not have permission to open this room"<<endl;
                        waitENTER();
                        break;
                    }
                    continue;
                }
                if(command != 4) continue;
                giveAccessPhase = 0;
            }
        }
    }
}

void UserInterfaceTerminal::printWelcomeText(University &university)
{
    cout<<"Welcome to "<<university.getName()<<endl;
    printSeparator();
    cout<<"Our university has:"<<endl;
    cout<<"\t"<<left<<setw(20)<<"1 director"                                                    <<"|\t"<<university.getCabinetRoom().size()<<" cabinets and 1 director's cabinet"<<endl;
    cout<<"\t"<<left<<setw(20)<<to_string(university.getAdmins().size())+" admins"              <<"|\t"<<university.getClassRoom().size()<<" class rooms"<<endl;
    cout<<"\t"<<left<<setw(20)<<to_string(university.getLabEmployees().size())+" lab employees" <<"|\t"<<university.getLectureRoom().size()<<" lecture rooms"<<endl;
    cout<<"\t"<<left<<setw(20)<<to_string(university.getProfessors().size())+" professors"      <<"|\t"<<university.getConferenceRoom().size()<<" conference rooms"<<endl;
    cout<<"\t"<<left<<setw(20)<<to_string(university.getStudents().size())+" students"          <<"|\t"<<university.getLivingRoom().size()<<" living rooms"<<endl<<endl;
    cout<<"Choose what you want to find out information about.\n\tPlease enter the {(0)People; (1)Room; (-)exit }"<<endl;

}

void UserInterfaceTerminal::printSeparator()
{
    cout<<LINE<<endl;
}

void UserInterfaceTerminal::getInput(string &input)
{
    cout<<'>';cin>>input;
}

void UserInterfaceTerminal::waitENTER()
{
    cout<<"return back. Press ENTER"<<endl;
    cin.get();
    string s;
    getline(cin,s);
}

bool UserInterfaceTerminal::isNumber(const string &num)
{
    return (num.find_first_not_of( "0123456789" ) == std::string::npos);
}

void UserInterfaceTerminal::clear()
{
    system("cls");
}

template<class T>
int UserInterfaceTerminal::calculateInput(string input, std::initializer_list<T> list)
{
    unsigned int i=0;
    if((isNumber(input))){
        i = stoi(input);
        if( i >= list.size()) return -1;
        return i;
    }
    for(const auto& str: list)
        if(input == str)
            return i;
        else i++;
    return -1;
}
