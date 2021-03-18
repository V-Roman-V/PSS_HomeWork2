#include "University_classes/university.h"
#include "University_classes/universityfiller.h"
#include "UserInterface_classes/Terminal/userinterfaceterminal.h"
using namespace std;

int main()
{
    University Innopolis("Innopolis University");

    UniversityFiller::fillStartingData(Innopolis);

    UserInterfaceTerminal::start(Innopolis);

    return 0;
}
