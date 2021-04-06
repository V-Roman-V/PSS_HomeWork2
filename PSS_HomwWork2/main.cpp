#include "University_classes/university.h"
#include "University_classes/universityfiller.h"
#include "UserInterface_classes/Terminal/userinterfaceterminal.h"
#include "UserInterface_classes/GUI/userinterfacegui.h"
using namespace std;

int main(int argc, char *argv[])
{
    University Innopolis("Innopolis University");

    UniversityFiller::fillStartingData(Innopolis);

    UserInterfaceTerminal::start(Innopolis);
//    UserInterfaceGUI::start(argc,argv);

    return 0;
}
