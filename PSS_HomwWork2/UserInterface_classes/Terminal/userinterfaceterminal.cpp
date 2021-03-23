#include "userinterfaceterminal.h"

const std::string UserInterfaceTerminal::LINE = "---------------------------------------------------------";
Logger UserInterfaceTerminal::logger;

using namespace std;
void UserInterfaceTerminal::start(University& university)
{
    logger.updatePeople(university.getFullListPeoples());
    logger.updateRoom  (university.getListRooms());

    static const vector<string> twoTypes = {"People","Room"};

    static const vector<string> allroomTypes = {"cabinet","class","lecture","conference","living"};
    static const vector<string> uniRoomTypes = {"cabinet","class","lecture","conference"};
    static const vector<string> uniRoomTypesWA = {"cabinet = "+Cabinet::getNeededLevel(),"class = "+ClassRoom::getNeededLevel(),"lecture = "+LectureRoom::getNeededLevel(),"conference = "+ConferenceRoom::getNeededLevel()};

    static const vector<string> peopleTypes = {"director","admin","labEmployee","professor","student"};
    static const vector<string> peopleTypesWODir = {"admin","labEmployee","professor","student"};

    static const vector<string> accessLevels = {"noLevel", "green", "yellow", "red", "black"};

    static const vector<string> consent = {"confirm", "cancel"};

    static const vector<string> allComands = {"logOut","myInfo","myMovementsHistory","tryOpenRoom","giveAccess"};
    static const vector<string> userCommands ={"logOut","myInfo","myMovementsHistory","tryOpenRoom"};

    string input;
    while(true){ // position selection
        clear();
        printWelcomeText(university);
        getInput(input);
        if(input == "-" or input == "exit") break;

        int sphere = calculateInput(input,twoTypes);
        if( sphere == -1) continue;
        printSeparator();
        if(sphere == 1){ //rooms
            cout<<"You can read the list in detail. \n\tPlease enter the room type "<<getListOptions(allroomTypes)<<endl;
            getInput(input);
            int type = calculateInput(input, allroomTypes);
            if( type == -1) continue;
            vector<Room*> rooms;
            switch(type){
                case 0:rooms = vector<Room*>(university.getCabinetRoom().begin(),university.getCabinetRoom().end()); rooms.push_back(university.getDirectorCabinet());break;
                case 1:rooms = vector<Room*>(university.getClassRoom().begin(),university.getClassRoom().end());break;
                case 2:rooms = vector<Room*>(university.getLectureRoom().begin(),university.getLectureRoom().end());break;
                case 3:rooms = vector<Room*>(university.getConferenceRoom().begin(),university.getConferenceRoom().end());break;
                case 4:rooms = vector<Room*>(university.getLivingRoom().begin(),university.getLivingRoom().end());break;
            }
            logger.addActions("Read informations about rooms : "+ allroomTypes[type]);
            int i=1;
            for(auto r: rooms)
                cout<<" "<<i++<<") "<<r->getInfo()<<endl;
            printSeparator();
            waitENTER();
            continue;
        }

        cout<<"You can read the list in detail. \n\tPlease enter the position name "<<getListOptions(peopleTypes)<<endl;
        getInput(input);
        int position = calculateInput(input,peopleTypes);
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
        logger.addActions("Read informations about people: "+ peopleTypes[position]);

        bool incorrect_pass = false;
        int chosen_person = 0;
        while(true){ // Person selection
            clear();
            cout<<peopleTypes[position]<<" in "<<university.getName()<<":"<<endl<<endl;
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
                logger.addActions("Want log in as admin");
                printSeparator();
                cout<<"Since you are trying to log in as an administrator, you need to enter your password."<<endl;
                cout<<"\tPlease enter the password."<<endl;
                getInput(input);
                Admin* admin = static_cast<Admin *>(person);
                if(!admin->checkPassword(input)){
                    logger.addActions("Entered password is not correct");
                    incorrect_pass= true;
                    continue;
                }
                logger.addActions("Entered password is correct");
            }
            incorrect_pass = false;

            logger.addActions("Log in as: "+ person->getCommonInfo());

            int giveAccessPhase = -1;
            UniversityPeople* selected_person = nullptr;
            UniversityRoom*   selected_room = nullptr;
            AccessLevel       selected_level = AccessLevel::no_level;
            while(true){
                clear();
                cout<<"You are login to the system as "<<person->getName() <<((isAdmin)?" (Administrator)":"")<<endl;
                cout<<"You can log out, display information about yourself, see the history of your movements,"<<(isAdmin?"":" and")<<" try to enter the room"<<(isAdmin?", and give access to people.":".")<<endl;
                cout<<"\tPlease enter the command "<<getListOptions(isAdmin?allComands:userCommands)<<endl;
                //----- give access phase
                if(giveAccessPhase == 0){ // chosen person
                    cout<<">4"<<endl;
                    printSeparator();
                    cout<<"Choose the person you want to give access."<<endl;
                    cout<<"\tPlease enter the position name "<<getListOptions(peopleTypesWODir)<<endl;
                    getInput(input);
                    int position = calculateInput(input, peopleTypesWODir);
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
                        cout<<peopleTypesWODir[position]<<":"<<endl<<endl;
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
                    cout<<"\tPlease enter the type "<<getListOptions({"room", "accessLevel", "back"})<<endl;
                    getInput(input);
                    if(input == "back" or input == "-"){giveAccessPhase = -1;continue;}
                    int Atype = calculateInput(input,{"room","accessLevel"});
                    if( Atype == -1) continue;
                    if(Atype == 1){
                        printSeparator();
                        cout<<"Choose the level you want to give the person."<<endl;
                        cout<<"\tPlease enter the level "<<getListOptions(accessLevels)<<endl;
                        getInput(input);
                        int access = calculateInput(input,accessLevels);
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
                    cout<<"\tPlease enter the room type "<<getListOptions(uniRoomTypes)<<endl;
                    getInput(input);
                    int type = calculateInput(input,uniRoomTypes);
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
                        cout<<uniRoomTypes[type]<<":"<<endl;

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
                    cout<<"Confirm your choice or cancel it\n\tPlease enter the "<<getListOptions(consent)<<endl;
                    getInput(input);
                    int confirm = calculateInput(input,consent);
                    if( confirm == -1) continue;
                    if( confirm == 0){
                        Admin* admin = static_cast<Admin*>(person);
                        admin->giveAccess(selected_person,selected_level);
                        cout<<"The level was successfully assigned"<<endl;
                        logger.addActions("Give the "+selected_person->getName()+" new access level: "+getAccessLevelName(selected_level));
                        logger.updatePeople(university.getFullListPeoples());
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
                    cout<<"Confirm your choice or cancel it\n\tPlease enter the "<<getListOptions(consent)<<endl;
                    getInput(input);
                    int confirm = calculateInput(input,consent);
                    if( confirm == -1) continue;
                    if(confirm == 0){
                        Admin* admin = static_cast<Admin*>(person);
                        admin->giveAccess(selected_person,selected_room);
                        cout<<"Special access to the room was successfully assigned"<<endl;
                        logger.addActions("Give the "+selected_person->getName()+" new access to the room: "+selected_room->getInfo());
                        logger.updatePeople(university.getFullListPeoples());
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
                int command = calculateInput(input, allComands);
                if( command == -1) continue;
                if( command == 4 && !isAdmin) continue;

                if(command == 0) {
                    logger.addActions("Log out");
                    break;
                }
                if(command == 1) {
                    logger.addActions("Read full info");
                    cout<<" "<<person->getFullInfo()<<endl;
                    waitENTER();
                    continue;
                }
                if(command == 2) {
                    logger.addActions("Read movement history");
                    cout<<"\tMy movements history: "<<endl;
                    cout<<" "<<person->getMovementHistory()<<endl;
                    waitENTER();
                    continue;
                }
                if(command == 3){
                    printSeparator();
                    cout<<"You can try to open one of the university rooms. Your access level: "<<person->getAccessLevel()<<endl;
                    cout<<"\tPlease enter the room type "<<getListOptions(uniRoomTypesWA)<<endl;
                    getInput(input);
                    int type = calculateInput(input, uniRoomTypes);
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
                        cout<<uniRoomTypes[type]<<":"<<endl;

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
                        if(open){
                            cout<<"You were able to open the door"<<endl;
                            logger.addActions("Successfully entered the room: "+rooms[room_num-1]->getInfo());
                        }else{
                            cout<<"You do not have permission to open this room"<<endl;
                            logger.addActions("Failed to enter the room: "+rooms[room_num-1]->getInfo());
                        }
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
    cout<<"Choose what you want to find out information about.\n\tPlease enter the "<<getListOptions({"People", "Room", "exit" })<<endl;

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

string UserInterfaceTerminal::getListOptions(std::vector<string> list)
{
    string out ="{";
    for(unsigned int i=0;i<list.size();i++)
        out += "(" + ((list[i]=="exit")?"-":to_string(i)) + ")" + list[i] + ((i+1==list.size())?"}":"; ");
    return out;
}

int UserInterfaceTerminal::calculateInput(string input, vector<string> list)
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
