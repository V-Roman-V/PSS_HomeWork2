#include <fstream>

#include "University_classes/university.h"
#include "University_classes/universityfiller.h"
#include "UserInterface_classes/Terminal/userinterfaceterminal.h"

using namespace std;

int main()
{
    ofstream logPeople("log_people.txt");
    ofstream logRoom("log_room.txt");
    ofstream logActions("log_actions.txt");

    University Innopolis("Innopolis University");

    UniversityFiller::fillStartingData(Innopolis);

// ---------------------------------------------------------- Write Peoples and Rooms in log files

    logPeople<<Innopolis.getFullListPeoples();
    logPeople<<"___________________________________"<<endl;
    logPeople<<Innopolis.getCommonListPeoples();
    logRoom<<Innopolis.getListRooms();
// ----------------------------------------------------------

    UserInterfaceTerminal::start(Innopolis);
    return 0;
}
