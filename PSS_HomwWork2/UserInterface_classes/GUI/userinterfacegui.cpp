#include "userinterfacegui.h"

int UserInterfaceGUI::start(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
