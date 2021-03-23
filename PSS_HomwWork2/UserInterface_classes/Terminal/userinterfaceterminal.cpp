#include "userinterfaceterminal.h"

const std::string UserInterfaceTerminal::LINE = "---------------------------------------------------------";
Logger UserInterfaceTerminal::logger;

using namespace std;
void UserInterfaceTerminal::start(University& university)
{
    logger.updatePeople(university.getFullListPeoples());
    logger.updateRoom  (university.getListRooms());

    static const vector<string> twoTypes = {"People","Room"};

    const vector<RoomType> allroomTypes = university.getAllRoomType();
    const vector<RoomType> uniRoomTypes(allroomTypes.begin(), allroomTypes.end()-1);
    vector<string> uniRoomTypesWA = university.getAllRoomAccess(); // may update

    const vector<Position> peopleTypes = university.getAllPositions();
    const vector<Position> peopleTypesWODir(peopleTypes.begin()+1,peopleTypes.end());

    const vector<AccessLevel> accessLevels = university.getAllAccessLevels();

    static const vector<string> consent = {"confirm", "cancel"};

    static const vector<string> allComands = {"logOut","myInfo","myMovementsHistory","tryOpenRoom","emergency","giveAccess"};
    static const vector<string> userCommands(allComands.begin(), allComands.end()-1);

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
            university.getRoomByType(allroomTypes[type], rooms);
            logger.addActions("Read informations about rooms : " + UniversityRoom::getRoomTypeName(allroomTypes[type]));
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
        university.getPeopleByType(peopleTypes[position], peoples);
        logger.addActions("Read informations about people: " + UniversityPeople::getPozitionName(peopleTypes[position]));

        bool incorrect_pass = false;
        int chosen_person = 0;
        while(true){ // Person selection
            clear();
            cout<<UniversityPeople::getPozitionName(peopleTypes[position])<<" in "<<university.getName()<<":"<<endl<<endl;
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
            bool isAdmin = person->isAdmin();

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
                cout<<"You are login to the system as "<<person->getName() <<((isAdmin)?" (you are administrator)":"")<<endl;
                cout<<"You can log out, display information about yourself, see the history of your movements,"<<(isAdmin?"":" and")<<" try to enter the room"<<(isAdmin?", and give access to people.":".")<<endl;
                if(university.isEmergency())
                    cout<<"-------Attention emergency-------"<<endl;
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
                    university.getPeopleByType(peopleTypesWODir[position], peoples);
                    while(true){ // Person selection to give access
                        clear();
                        cout<<UniversityPeople::getPozitionName(peopleTypesWODir[position])<<":"<<endl<<endl;
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
                        selected_level = accessLevels[access];
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
                    vector<Room*> rooms;
                    university.getRoomByType(uniRoomTypes[type], rooms);

                    while(true) {
                        clear();
                        cout<<UniversityRoom::getRoomTypeName(uniRoomTypes[type])<<":"<<endl;

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
                        selected_room =  static_cast<UniversityRoom*> (rooms[room_num-1]);
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
                int command = calculateInput(input, isAdmin?allComands:userCommands);
                if( command == -1) continue;

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
                if(command == 3) {
                    vector<string> uniRoomTypesWA = university.getAllRoomAccess(); // may update
                    printSeparator();
                    cout<<"You can try to open one of the university rooms. Your access level: "<<getAccessLevelName(person->getAccessLevel())<<endl;
                    cout<<"\tPlease enter the room type "<<getListOptions(uniRoomTypesWA)<<endl;
                    getInput(input);
                    int type = calculateInput(input, uniRoomTypes);
                    if( type == -1) continue;
                    vector<Room*> rooms;
                    university.getRoomByType(uniRoomTypes[type], rooms);
                    while(true) { // trying open room
                        clear();
                        cout<<UniversityRoom::getRoomTypeName(uniRoomTypes[type])<<":"<<endl;

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
                        bool open = person->tryToEnter(static_cast<UniversityRoom*>(rooms[room_num-1]));
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
                if(command == 4) {
                    if(university.isEmergency() && person->getAccessLevel()<AccessLevel::red){
                        cout<<"To turn off the alarm, you must have a red access level or higher"<<endl;
                        waitENTER();
                        continue;
                    }
                    if(university.isEmergency() && person->getAccessLevel()>=AccessLevel::red){
                        cout<<"Do you want to turn off the alarm?"<<endl;
                        printSeparator();
                        cout<<"Confirm your choice or cancel it\n\tPlease enter the "<<getListOptions(consent)<<endl;
                        getInput(input);
                        int confirm = calculateInput(input,consent);
                        if( confirm != 0) continue;
                        university.stopEmergency();
                        cout<<"The alarm has been stopped"<<endl;
                        logger.addActions("Person "+person->getName()+ " stopped the alarm system");
                        waitENTER();
                        continue;
                    }
                    cout<<"Do you want to turn on the alarm?"<<endl;
                    printSeparator();
                    cout<<"Confirm your choice or cancel it\n\tPlease enter the "<<getListOptions(consent)<<endl;
                    getInput(input);
                    int confirm = calculateInput(input,consent);
                    if( confirm != 0) continue;
                    university.startEmergency();
                    cout<<"The alarm was turned on"<<endl;
                    logger.addActions("Person "+person->getName()+ " started the alarm system");
                    waitENTER();
                    continue;
                }
                if(command != 5) continue;
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

void UserInterfaceTerminal::waitENTER()
{
    cout<<"return back. Press ENTER"<<endl;
    cin.get();
    string s;
    getline(cin,s);
}

template<class T>
string UserInterfaceTerminal::getListOptions(const vector<T>& list, string (*to_str)(const T&))
{
    string out ="{";
    for(unsigned int i=0;i<list.size();i++)
        out += "(" + ( (to_str(list[i])=="exit")?"-":to_string(i)) + ")" + to_str(list[i]) + ((i+1==list.size())?"}":"; ");
    return out;
}

template<class T>
int UserInterfaceTerminal::calculateInput(const string& input, const vector<T>& list, string (*to_str)(const T &))
{
    unsigned int i=0;
    if((isNumber(input))){
        i = stoi(input);
        if( i >= list.size()) return -1;
        return i;
    }
    for(const auto& str: list)
        if(input == to_str(str))
            return i;
        else i++;
    return -1;
}
